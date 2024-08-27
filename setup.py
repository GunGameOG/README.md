from setuptools import setup, find_packages

setup(
    name="ddos_detector",
    version="0.1",
    packages=find_packages(),
    entry_points={
        'console_scripts': [
            'ddos-detect=ddos_detector.ddos_detect:main',
        ],
    },
    install_requires=[
        'bcc',
    ],
    include_package_data=True,
    description="A tool for detecting and mitigating DDoS attacks using XDP and BPF",
    author="Your Name",
    author_email="your.email@example.com",
    url="https://github.com/yourusername/ddos_detector",
    classifiers=[
        'Programming Language :: Python :: 3',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
    ],
)
