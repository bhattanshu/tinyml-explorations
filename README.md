# TinyML Explorations
## Idea
Our project aims to bring computer vision capabilities to perimeter access control devices using TinyML. We're building a low-power, always-on image recognition solution that runs directly on edge hardware with models trained using TensorFlow Lite.

The prototype will demonstrate the ability to recognize two distinct objects using an on-device TinyML model. This paves the way for face-based access control, where authorized residents could be granted entry based on visual identification — without needing cloud computation or active internet connections.

## Why it Matters
Traditional smart security systems often rely on cloud-based image processing, which introduces latency, privacy risks, and dependency on connectivity. In contrast, our TinyML solution offers:

- Low-latency, on-device inference
- Enhanced privacy, as data doesn’t leave the device
- Energy efficiency, ideal for battery-operated IoT security hardware
- Offline capability, making it more robust and cost-effective

By enabling real-time, local decision-making, this solution can empower even low-cost perimeter devices with advanced intelligence.

## Difference it can make
This project can evolve into a scalable framework for edge-based visual monitoring, with real-world applications like:

- Face recognition-based smart access control for gated communities, apartments, or workplaces
- Anomaly detection: flagging "unusual" activity — such as unfamiliar objects or suspicious motion patterns — and automatically:
   - Triggering nearby (assigned to the same zone) video-enabled devices to record
   - Alerting property managers or security personnel
   - Creating a distributed, intelligent video surveillance network — all without centralized processing

By pushing intelligence to the edge, this approach could reduce infrastructure costs (on the cloud), increase responsiveness, and enhance privacy and reliability in residential or commercial access control systems.

## Hackathon Deliverable
Our hackathon output is a working prototype that:
- Uses an Arduino Nano 33 BLE Sense
- Runs a TensorFlow Lite image classification model (TinyML)
- Can uniquely identify two objects/faces
- Demonstrates how on-device image recognition can be used for secure access or anomaly detection triggers

This repository contains experiments, sample projects, and scripts for exploring TinyML (machine learning on microcontrollers and edge devices).

## Structure

- `samples/board-connections/blink/` — Example Arduino sketches for board setup and basic I/O (e.g., blink demo)
- `python_scripts/` — Python scripts for data collection, preprocessing, and dataset creation
- Other folders may include model training, deployment, and hardware integration examples

## Getting Started

1. **Hardware Requirements**
   - Arduino Nano 33 BLE, OV7675 Camera Module, or other supported microcontroller
   - USB data cable

2. **Software Requirements**
   - [Arduino IDE](https://www.arduino.cc/en/software) or [arduino-cli](https://arduino.github.io/arduino-cli/)
   - Python 3.8+
   - Required Python packages (see individual script requirements)
   - Google Colab Notebook - For model training and testing

3. **Setup**
   - Install Arduino board support packages via Arduino IDE or arduino-cli
   - Connect your board and verify with `arduino-cli board list`
   - Compile and upload sketches from the `samples/` directory
   - Run Python scripts from `python_scripts/` for data tasks
   - Google Drive account

- `samples/` — Example Arduino sketches and board connection demos for hardware setup and basic I/O
- `python_scripts/` — Python scripts for data collection, preprocessing, and dataset creation
- `camera/` — Camera interface and conversion utilities for image acquisition and format conversion
- `colabs/` — Jupyter/Colab notebooks for prototyping, model training, and hackathon experiments
- `dataset/` — Organized image datasets for training/testing (e.g., allow/deny/call classes)
- `guardshack_ml/` — Main application code and logic for the perimeter access control prototype
- `model/` — Trained TinyML models and headers for deployment (e.g., TensorFlow Lite files)


## Troubleshooting

- If upload fails, check USB cable, port, drivers, and board selection
- For include errors in VS Code, update `.vscode/c_cpp_properties.json` with correct Arduino core paths

## License

MIT License

## Author

Anshu Bhatt
