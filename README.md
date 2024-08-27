# DDoS Detector

This package provides a tool for detecting and mitigating DDoS attacks using XDP and BPF.

## Installation

1. Clone the repository:
    ```sh
    git clone https://github.com/GunGameOG/ddos_detector.git
    cd ddos_detector
    ```

2. Install the package:
    ```sh
    sudo python3 setup.py install
    ```

## Usage

Run the DDoS detection tool:
```sh
sudo ddos-detect
```

Ensure you have root privileges as the tool requires access to low-level networking functions.
