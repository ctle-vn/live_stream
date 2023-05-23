#include <iostream>
#include <librtmp/rtmp.h>

int main()
{
    RTMP *server = RTMP_Alloc();
    RTMP_Init(server);

    // Set up the server to listen on port 1935
    if (!RTMP_SetupURL(server, "rtmp://0.0.0.0:1935/live/stream"))
    {
        std::cerr << "SetupURL Error\n";
        RTMP_Free(server);
        return -1;
    }

    RTMP_EnableWrite(server);  // Enable server mode

    // Wait for a connection from the client
    if (!RTMP_Connect(server, NULL) || !RTMP_ConnectStream(server, 0))
    {
        std::cerr << "Connect Error\n";
        RTMP_Close(server);
        RTMP_Free(server);
        return -1;
    }

    while (true)
    {
        // Read an RTMP packet from the client
        RTMPPacket packet = {0};
        if (RTMP_ReadPacket(server, &packet) && RTMPPacket_IsReady(&packet))
        {
            // If the packet contains audio or video data, send it back to the client
            if (packet.m_packetType == RTMP_PACKET_TYPE_AUDIO || packet.m_packetType == RTMP_PACKET_TYPE_VIDEO)
            {
                RTMP_SendPacket(server, &packet, 0);
            }

            // Free the packet after use
            RTMPPacket_Free(&packet);
        }
    }

    // Clean up
    RTMP_Close(server);
    RTMP_Free(server);

    return 0;
}
