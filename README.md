# MATLAB-STM32-Control-Lab
This project demonstrates real-time communication between **MATLAB App Designer** and an **STM32F7 microcontroller** for digital control experiments.

## 🧩 Components

### 🧠 MATLAB App
- File: `LabFinalTopicos.mlapp`
- Functions:
  - Selects input type: Step, Ramp, Sine
  - Selects control type: Servo or Root-Locus (LGR)
  - Sends command via serial port (COM2)
  - Plots signals: Input, Theta1, Theta2, Error

### ⚙️ STM32 Firmware
- File: `main.c`
- Receives serial commands (`a`–`g`)
- Generates input signals and simulates two discrete-time plants (P1 and P2)
- Sends response data back to MATLAB

## 🔌 Communication
- UART4 @ 9600 baud (TX=PC10, RX=PC11)
- MATLAB reads 255 samples per channel (Input, P1, P2, Error)

## 💡 How to Use
1. Flash the STM32 firmware to your board (via ST-Link or USB).
2. Run the MATLAB app (`LabFinalTopicos.mlapp`).
3. Select input and control type.
4. Press “Iniciar” to start real-time data collection.
5. Observe the plots for input, outputs, and error.

---
> ⚠️ Academic Disclaimer  
> This project was developed as part of the  
> Topicos Avanzados de Control module at **Universidad Militar Nueva Granada (2017–2021)**.  
> The content is shared for educational and portfolio purposes only.  
> No proprietary or restricted university materials are included.
