#include <stdint.h>

#include "SlimLoRa.h"

void setup() {
    uint8_t payload[3], payload_length;
    uint8_t fport = 1;
    SlimLoRa lora = SlimLoRa(8);

    delay(1000);

    lora.Begin();

#if LORAWAN_OTAA_ENABLED
    while (!lora.HasJoined()) {
        lora.Join();
        delay(1000);
    }
#endif // LORAWAN_OTAA_ENABLED

    payload_length = sizeof(payload);
    payload[0] = 0x01;
    payload[1] = 0x10;
    payload[2] = 0xFF;

    lora.SendData(fport, payload, payload_length);
}

void loop() { }
