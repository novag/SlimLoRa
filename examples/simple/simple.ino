#include <stdint.h>

#include "config.h"
#include "SlimLoRa.h"

void setup() {
    uint8_t payload[3], payload_length;
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
    payload[0] = 0xAB;
    payload[1] = 0xCD;
    payload[2] = 0xEF;

    lora.SendData(fport, payload, payload_length);
}

void loop() { }