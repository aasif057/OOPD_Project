
# WiFi Simulator Project

## Overview

This project simulates the communication protocols for WiFi 4, WiFi 5, and WiFi 6. The simulation models access points (AP), users, packets, frequency channels, and communication mechanisms like CSMA/CA (for WiFi 4), MU-MIMO (for WiFi 5), and OFDMA (for WiFi 6). The main objectives are to simulate the communication behavior, calculate throughput, average latency, and maximum latency based on the number of users connected to the access point.

## Features

- **WiFi 4**: Implements CSMA/CA for single-user communication with backoff and retry mechanisms.
- **WiFi 5**: Implements Multi-User MIMO (MU-MIMO) for parallel communication with round-robin scheduling.
- **WiFi 6**: Implements Orthogonal Frequency-Division Multiple Access (OFDMA) for subdividing a 20 MHz channel into smaller sub-channels.
  
## Structure

### `WiFi.h`:
- A base class for all WiFi types that defines virtual methods for simulation (`simulate` and `setNumUsers`).
  
### `WiFi4.h`, `WiFi5.h`, `WiFi6.h`:
- Derived classes that implement the simulation for each WiFi protocol (WiFi 4, 5, and 6).
  
### `WiFi4.cpp`, `WiFi5.cpp`, `WiFi6.cpp`:
- Implementations of the specific WiFi simulations, each including protocol-specific features like CSMA/CA, MU-MIMO, and OFDMA.

### `AccessPoint.h` / `AccessPoint.cpp`:
- Models the access point and its interactions with users, including packet transmission and channel management.

### `User.h` / `User.cpp`:
- Models the user, including packet generation and transmission.

### `Packet.h` / `Packet.cpp`:
- Models the data packets used for communication, with attributes such as packet size and data transmission time.

### `FrequencyChannel.h` / `FrequencyChannel.cpp`:
- Models the frequency channel, including sub-channel allocation and bandwidth management for WiFi 6.

### `main.cpp`:
- Entry point for the simulation. Takes user input for the number of users and WiFi type, runs the simulation, and outputs the results.
- We are taking which type of Wifi to simulate as input and then number of users as input

## Compilation

To compile the project, run:

```bash
make
```

This will compile all the source files and generate an executable named `WiFiSimulator`.

## Usage

Once compiled, run the simulator by executing the following command:

```bash
./WiFiSimulator
```

### Example Output:
```
Enter WiFi type (4 for WiFi4, 5 for WiFi5, 6 for WiFi6): 5
Enter number of users: 10
Throughput: 0.546133 Mbps
Average Latency: 15 ms
Maximum Latency: 15 ms
```
### Source

I have taken help from ChatGPT for some part of the code.