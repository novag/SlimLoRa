#ifndef SLIM_LORA_H
#define SLIM_LORA_H

#include <stddef.h>
#include <stdint.h>
#include <util/atomic.h>

// LoRaWAN ADR
#define LORAWAN_ADR_ACK_LIMIT   48
#define LORAWAN_ADR_ACK_DELAY   16

// Enable LoRaWAN Over-The-Air Activation
#define LORAWAN_OTAA_ENABLED    1
#define LORAWAN_KEEP_SESSION    1

#define MICROS_PER_SECOND               1000000

// RFM registers
#define RFM_REG_FIFO                    0x00
#define RFM_REG_OP_MODE                 0x01
#define RFM_REG_FR_MSB                  0x06
#define RFM_REG_FR_MID                  0x07
#define RFM_REG_FR_LSB                  0x08
#define RFM_REG_PA_CONFIG               0x09
#define RFM_REG_FIFO_ADDR_PTR           0x0D
#define RFM_REG_FIFO_TX_BASE_ADDR       0x0E
#define RFM_REG_FIFO_RX_BASE_ADDR       0x0F
#define RFM_REG_FIFO_RX_CURRENT_ADDR    0x10
#define RFM_REG_IRQ_FLAGS_MASK          0x11
#define RFM_REG_IRQ_FLAGS               0x12
#define RFM_REG_RX_NB_BYTES             0x13
#define RFM_REG_PKT_SNR_VALUE           0x19
#define RFM_REG_PKT_RSSI_VALUE          0x1A
#define RFM_REG_MODEM_CONFIG_1          0x1D
#define RFM_REG_MODEM_CONFIG_2          0x1E
#define RFM_REG_SYMB_TIMEOUT_LSB        0x1F
#define RFM_REG_PREAMBLE_MSB            0x20
#define RFM_REG_PREAMBLE_LSB            0x21
#define RFM_REG_PAYLOAD_LENGTH          0x22
#define RFM_REG_MODEM_CONFIG_3          0x26
// Only in SX1276 datasheet
#define RFM_REG_IF_FREQ_2               0x2F
#define RFM_REG_IF_FREQ_1               0x30
#define RFM_REG_DETECT_OPTIMIZE         0x31
#define RFM_REG_INVERT_IQ               0x33
#define RFM_REG_SYNC_WORD               0x39
#define RFM_REG_INVERT_IQ_2             0x3B

// RFM status
#define RFM_STATUS_TX_DONE              0x08
#define RFM_STATUS_RX_DONE              0x40
#define RFM_STATUS_RX_DONE_CRC_ERROR    0x60
#define RFM_STATUS_RX_TIMEOUT           0x80

#define RFM_ERROR_RX_TIMEOUT    -1
#define RFM_ERROR_CRC           -2
#define RFM_ERROR_UNKNOWN       -3

// LoRaWAN
#define LORAWAN_MTYPE_JOIN_REQUEST          0x00
#define LORAWAN_MTYPE_JOIN_ACCEPT           0x20
#define LORAWAN_MTYPE_UNCONFIRMED_DATA_UP   0x40
#define LORAWAN_MTYPE_UNCONFIRMED_DATA_DOWN 0x60
#define LORAWAN_MTYPE_CONFIRMED_DATA_UP     0x80
#define LORAWAN_MTYPE_CONFIRMED_DATA_DOWN   0xA0
#define LORAWAN_MTYPE_RFU                   0xC0
#define LORAWAN_MTYPE_PROPRIETARY           0xE0

#define LORAWAN_FCTRL_ADR                   0x80
#define LORAWAN_FCTRL_ADR_ACK_REQ           0x40
#define LORAWAN_FCTRL_ACK                   0x20

#define LORAWAN_DIRECTION_UP                0
#define LORAWAN_DIRECTION_DOWN              1

#define LORAWAN_UPLINK_CHANNEL_COUNT        8

// LoRaWAN frame options
#define LORAWAN_FOPT_LINK_CHECK_REQ         0x02
#define LORAWAN_FOPT_LINK_CHECK_ANS         0x02
#define LORAWAN_FOPT_LINK_ADR_REQ           0x03
#define LORAWAN_FOPT_LINK_ADR_ANS           0x03
#define LORAWAN_FOPT_DUTY_CYCLE_REQ         0x04
#define LORAWAN_FOPT_DUTY_CYCLE_ANS         0x04
#define LORAWAN_FOPT_RX_PARAM_SETUP_REQ     0x05
#define LORAWAN_FOPT_RX_PARAM_SETUP_ANS     0x05
#define LORAWAN_FOPT_DEV_STATUS_REQ         0x06
#define LORAWAN_FOPT_DEV_STATUS_ANS         0x06
#define LORAWAN_FOPT_NEW_CHANNEL_REQ        0x07
#define LORAWAN_FOPT_NEW_CHANNEL_ANS        0x07
#define LORAWAN_FOPT_RX_TIMING_SETUP_REQ    0x08
#define LORAWAN_FOPT_RX_TIMING_SETUP_ANS    0x08
#define LORAWAN_FOPT_TX_PARAM_SETUP_REQ     0x09
#define LORAWAN_FOPT_TX_PARAM_SETUP_ANS     0x09
#define LORAWAN_FOPT_DL_CHANNEL_REQ         0x0A
#define LORAWAN_FOPT_DL_CHANNEL_ANS         0x0A
#define LORAWAN_FOPT_DEVICE_TIME_REQ        0x0D
#define LORAWAN_FOPT_DEVICE_TIME_ANS        0x0D

// LoRaWAN frame option payload size
#define LORAWAN_FOPT_LINK_CHECK_ANS_SIZE        2
#define LORAWAN_FOPT_LINK_ADR_REQ_SIZE          4
#define LORAWAN_FOPT_DUTY_CYCLE_REQ_SIZE        1
#define LORAWAN_FOPT_RX_PARAM_SETUP_REQ_SIZE    4
#define LORAWAN_FOPT_DEV_STATUS_REQ_SIZE        2
#define LORAWAN_FOPT_NEW_CHANNEL_REQ_SIZE       5
#define LORAWAN_FOPT_RX_TIMING_SETUP_REQ_SIZE   1
#define LORAWAN_FOPT_TX_PARAM_SETUP_REQ_SIZE    1
#define LORAWAN_FOPT_DL_CHANNEL_REQ_SIZE        4
#define LORAWAN_FOPT_DEVICE_TIME_ANS_SIZE       5

// LoRaWAN Join packet sizes
#define LORAWAN_JOIN_REQUEST_SIZE           18
#define LORAWAN_JOIN_ACCEPT_MAX_SIZE        28

// LoRaWAN delays in seconds
#define LORAWAN_JOIN_ACCEPT_DELAY1_MICROS   5 * MICROS_PER_SECOND
#define LORAWAN_JOIN_ACCEPT_DELAY2_MICROS   6 * MICROS_PER_SECOND

#define LORAWAN_RX_ERROR_MICROS             10000   // 10 ms
#define LORAWAN_RX_MARGIN_MICROS            2000    // 2000 us
#define LORAWAN_RX_SETUP_MICROS             2000    // 2000 us
#define LORAWAN_RX_MIN_SYMBOLS              6

#define LORAWAN_FOPTS_MAX_SIZE              10
#define LORAWAN_STICKY_FOPTS_MAX_SIZE       6

// EU868 region settings
#define LORAWAN_EU868_TX_POWER_MAX          7
#define LORAWAN_EU868_RX1_DR_OFFSET_MAX     5

// LoRaWAN Error
#define LORAWAN_ERROR_NO_PACKET_RECEIVED    -1
#define LORAWAN_ERROR_SIZE_EXCEEDED         -2
#define LORAWAN_ERROR_UNEXPECTED_MTYPE      -3
#define LORAWAN_ERROR_INVALID_FRAME_COUNTER -4
#define LORAWAN_ERROR_UNEXPECTED_DEV_ADDR   -5
#define LORAWAN_ERROR_INVALID_MIC           -6
#define LORAWAN_ERROR_INVALID_JOIN_NONCE    -7

// LoRaWAN spreading factors
#define SF7BW250    6
#define SF7BW125    5
#define SF8BW125    4
#define SF9BW125    3
#define SF10BW125   2
#define SF11BW125   1
#define SF12BW125   0


typedef struct {
    uint8_t length;
    uint8_t fopts[LORAWAN_FOPTS_MAX_SIZE];
} fopts_t;

typedef struct {
    uint8_t length;
    uint8_t fopts[LORAWAN_STICKY_FOPTS_MAX_SIZE];
} sticky_fopts_t;

class SlimLoRa {
  public:
    SlimLoRa(uint8_t pin_nss);
    void Begin(void);
    bool HasJoined(void);
    int8_t Join();
    void SendData(uint8_t fport, uint8_t *payload, uint8_t payload_length);
    void SetAdrEnabled(bool enabled);

  private:
    uint8_t pin_nss_;
    uint8_t channel_ = 0;
    uint8_t data_rate_ = SF10BW125;
    uint8_t rx1_data_rate_offset_ = 0;
    uint8_t rx2_data_rate_;
    uint32_t rx1_delay_micros_;
    bool has_joined_ = false;
    bool adr_enabled_ = true;
    uint16_t tx_frame_counter_ = 0;
    uint16_t rx_frame_counter_ = 0;
    uint8_t adr_ack_counter_ = 0;
    uint8_t pseudo_byte_;
    fopts_t pending_fopts_ = {0};
    fopts_t sticky_fopts_ = {0};
    uint8_t rx_symbols_ = LORAWAN_RX_MIN_SYMBOLS;
    unsigned long tx_done_micros_;
    int8_t last_packet_snr_;
    static const uint8_t kFrequencyTable[9][3];
    static const uint8_t kDataRateTable[7][3];
    static const uint32_t kDRMicrosPerHalfSymbol[7];
    static const uint8_t kSTable[16][16];
    int8_t RfmReceivePacket(uint8_t *packet, uint8_t packet_max_length, uint8_t channel, uint8_t dri, uint32_t rx_tickstamp);
    void RfmSendPacket(uint8_t *packet, uint8_t packet_length, uint8_t channel, uint8_t dri);
    void RfmWrite(uint8_t address, uint8_t data);
    uint8_t RfmRead(uint8_t address);
    uint32_t CalculateDriftAdjustment(uint32_t delay, uint16_t micros_per_half_symbol);
    int32_t CalculateRxWindowOffset(int16_t micros_per_half_symbol);
    uint32_t CalculateRxDelay(uint8_t data_rate, uint32_t delay);
    bool CheckMic(uint8_t *cmic, uint8_t *rmic);
    bool ProcessJoinAccept1_0(uint8_t *rfm_data, uint8_t rfm_data_length);
    bool ProcessJoinAccept1_1(uint8_t *rfm_data, uint8_t rfm_data_length);
    int8_t ProcessJoinAccept(uint8_t window);
    void ProcessFrameOptions(uint8_t *options, uint8_t f_options_length);
    int8_t ProcessDownlink(uint8_t window);
    void Transmit(uint8_t fport, uint8_t *payload, uint8_t payload_length);
    void EncryptPayload(uint8_t *payload, uint8_t payload_length, unsigned int frame_counter, uint8_t direction);
    void CalculateMic(const uint8_t *key, uint8_t *data, uint8_t *initial_block, uint8_t *final_mic, uint8_t data_length);
    void CalculateMessageMic(uint8_t *data, uint8_t *final_mic, uint8_t data_length, unsigned int frame_counter, uint8_t direction);
    void GenerateKeys(const uint8_t *key, uint8_t *key1, uint8_t *key2);
    void ShiftLeftData(uint8_t *data);
    void XorData(uint8_t *new_data, uint8_t *old_data);
    void AesEncrypt(const uint8_t *key, uint8_t *data);
    void AesAddRoundKey(uint8_t *round_key, uint8_t (*state)[4]);
    uint8_t AesSubByte(uint8_t byte);
    void AesShiftRows(uint8_t (*state)[4]);
    void AesMixCollums(uint8_t (*state)[4]);
    void AesCalculateRoundKey(uint8_t round, uint8_t *round_key);

    // EEPROM
    uint16_t GetTxFrameCounter();
    void SetTxFrameCounter(uint16_t count);
    uint16_t GetRxFrameCounter();
    void SetRxFrameCounter(uint16_t count);
    uint8_t GetRx1DataRateOffset();
    void SetRx1DataRateOffset(uint8_t value);
    uint8_t GetRx2DataRate();
    void SetRx2DataRate(uint8_t value);
    uint8_t GetRx1Delay();
    void SetRx1Delay(uint8_t value);

#if LORAWAN_KEEP_SESSION
    bool GetHasJoined();
    void SetHasJoined(bool value);
#endif // LORAWAN_KEEP_SESSION
    void GetDevAddr(uint8_t *dev_addr);
    void SetDevAddr(uint8_t *dev_addr);
    uint16_t GetDevNonce();
    void SetDevNonce(uint16_t dev_nonce);
    uint32_t GetJoinNonce();
    void SetJoinNonce(uint32_t join_nonce);
    void GetAppSKey(uint8_t *key);
    void SetAppSKey(uint8_t *key);
    void GetFNwkSIntKey(uint8_t *key);
    void SetFNwkSIntKey(uint8_t *key);
    void GetSNwkSIntKey(uint8_t *key);
    void SetSNwkSIntKey(uint8_t *key);
    void GetNwkSEncKey(uint8_t *key);
    void SetNwkSEncKey(uint8_t *key);
};

#endif
