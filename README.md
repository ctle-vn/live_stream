## Simple RTMP Server in C++

This project is a simple RTMP server implemented in C++. It accepts a single connection from an RTMP client, reads the incoming audio and video packets, and sends them back to the client, effectively creating a 1-to-1 live stream.

NOTE: This server is intended for learning and demonstration purposes only. It does not support multiple clients, does not handle errors, and is not suitable for production use. For a real-world application, consider using a full-featured RTMP server like nginx with the RTMP module.

### Prerequisites

A C++ compiler supporting C++11
librtmp development files installed on your system
How to Build
Clone this repository.
Navigate to the cloned repository in your terminal.
Run the following command to compile the server:
bash

```
g++ -std=c++11 -o rtmp_server main.cpp -lrtmp
```

How to Run the Server
Run the compiled server with the following command:

bash

```
./rtmp_server
```

The server will start and listen for incoming RTMP connections on port 1935.

How to Use the Server
You'll need an RTMP client that can send and receive audio and video streams. Examples of such clients include OBS (Open Broadcaster Software) and FFmpeg.

To connect to the server, configure your client to use the following RTMP URL:

bash

```
rtmp://localhost:1935/live/stream
```

The client should then be able to send an audio/video stream to the server, and receive the same stream back from the server.

Remember that you need to replace main.cpp with the actual path and name of your C++ source file. If your project consists of multiple source files, you'll need to list all of them in the g++ command. You may also need to adjust the command based on your build system and project structure.
