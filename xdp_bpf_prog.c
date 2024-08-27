// ddos_detector/xdp_bpf_prog.c

#include <linux/bpf.h>
#include <linux/if_ether.h>
#include <linux/ip.h>
#include <linux/in.h>

BPF_HASH(ip_blacklist, u32, u32);

int xdp_ddos_detect(struct xdp_md *ctx) {
    // Obtain the data and data_end pointers
    void *data = (void *)(unsigned long)ctx->data;
    void *data_end = (void *)(unsigned long)ctx->data_end;

    // Check if the packet contains an IP header
    struct ethhdr *eth = data;
    if ((void *)(eth + 1) > data_end)
        return XDP_PASS;

    if (eth->h_proto != htons(ETH_P_IP))
        return XDP_PASS;

    // Parse the IP header
    struct iphdr *ip = data + sizeof(*eth);
    if ((void *)(ip + 1) > data_end)
        return XDP_PASS;

    u32 ip_src = ip->saddr;

    // Check if the source IP is in the blacklist
    u32 *blacklist_entry = ip_blacklist.lookup(&ip_src);
    if (blacklist_entry) {
        return XDP_DROP;
    }

    return XDP_PASS;
}
