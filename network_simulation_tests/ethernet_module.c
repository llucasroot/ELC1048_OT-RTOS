#define EMAC_RX_BUFFERS                               16
#define EMAC_TX_BUFFERS                               8
#define MAC_PHY_RETRY_MAX                             1000000
#define ETHERNET_CONF_ETHADDR0                        0x00
#define ETHERNET_CONF_ETHADDR0                        0x00
#define ETHERNET_CONF_ETHADDR1                        0x04
#define ETHERNET_CONF_ETHADDR2                        0x25
#define ETHERNET_CONF_ETHADDR3                        0x1C
#define ETHERNET_CONF_ETHADDR4                        0xA0
#define ETHERNET_CONF_ETHADDR5                        0x02
#define ETHERNET_CONF_IPADDR0                         192
#define ETHERNET_CONF_IPADDR1                         168
#define ETHERNET_CONF_IPADDR2                         0
#define ETHERNET_CONF_IPADDR3                         2
#define ETHERNET_CONF_GATEWAY_ADDR0                   192
#define ETHERNET_CONF_GATEWAY_ADDR1                   168
#define ETHERNET_CONF_GATEWAY_ADDR2                   0
#define ETHERNET_CONF_GATEWAY_ADDR3                   1
#define ETHERNET_CONF_NET_MASK0                       255
#define ETHERNET_CONF_NET_MASK1                       255
#define ETHERNET_CONF_NET_MASK2                       255
#define ETHERNET_CONF_NET_MASK3                       0
#define ETH_PHY_MODE                                  BOARD_EMAC_MODE_RMII

//A specific EMAC device and the receive data buffer must be defined; another ul_frm_size should be defined to trace the actual size of the data received.

static emac_device_t gs_emac_dev;
static volatile uint8_t gs_uc_eth_buffer[EMAC_FRAME_LENTGH_MAX];
uint32_t ul_frm_size;

void emac_init(void)
{
    sysclk_init();
    board_init();
    rstc_set_external_reset(RSTC, 13);
    rstc_reset_extern(RSTC);
    while (rstc_get_status(RSTC) & RSTC_SR_NRSTL) {
    };
    ul_delay = sysclk_get_cpu_hz() / 1000 / 3 * 400;
    while (ul_delay--); 
    pmc_enable_periph_clk(ID_EMAC);
    emac_option.uc_copy_all_frame = 0;
    emac_option.uc_no_boardcast = 0;
    memcpy(emac_option.uc_mac_addr, gs_uc_mac_address, sizeof(gs_uc_mac_address));
    gs_emac_dev.p_hw = EMAC;
    emac_dev_init(EMAC, &gs_emac_dev, &emac_option);
    NVIC_EnableIRQ(EMAC_IRQn);
    ethernet_phy_init(EMAC, BOARD_EMAC_PHY_ADDR, sysclk_get_cpu_hz()
    ethernet_phy_auto_negotiate(EMAC, BOARD_EMAC_PHY_ADDR
    ethernet_phy_set_link(EMAC, BOARD_EMAC_PHY_ADDR, 1)
//Workflow
//Ensure that conf_eth.h is present and contains the following configuration symbol. This configuration file is used by the driver and should not be included by the application.
//Define the receiving buffer size used in the internal EMAC driver. The buffer size used for RX is EMAC_RX_BUFFERS * 128. If it was supposed receiving a large number of frame, the EMAC_RX_BUFFERS should be set higher. E.g., the application wants to accept a ping echo test of 2048, the EMAC_RX_BUFFERS should be set at least (2048/128)=16, but as there are additional frames coming, a preferred number is 24 depending on a normal Ethernet throughput.
#define EMAC_RX_BUFFERS                               16
//Define the transmitting buffer size used in the internal EMAC driver. The buffer size used for TX is EMAC_TX_BUFFERS * 1518.
#define EMAC_TX_BUFFERS                               8
//Define maximum retry time for a PHY read/write operation.
#define MAC_PHY_RETRY_MAX                             1000000
//Define the MAC address. 00:04:25:1C:A0:02 is the address reserved for ATMEL, application should always change this address to its' own.
#define ETHERNET_CONF_ETHADDR0                        0x00
#define ETHERNET_CONF_ETHADDR1                        0x04
#define ETHERNET_CONF_ETHADDR2                        0x25
#define ETHERNET_CONF_ETHADDR3                        0x1C
#define ETHERNET_CONF_ETHADDR4                        0xA0
#define ETHERNET_CONF_ETHADDR5                        0x02
//Define the IP address configration used in the application. When DHCP is enabled, this configuration is not effected.
#define ETHERNET_CONF_IPADDR0                         192
#define ETHERNET_CONF_IPADDR1                         168
#define ETHERNET_CONF_IPADDR2                         0
#define ETHERNET_CONF_IPADDR3                         2
#define ETHERNET_CONF_GATEWAY_ADDR0                   192
#define ETHERNET_CONF_GATEWAY_ADDR1                   168
#define ETHERNET_CONF_GATEWAY_ADDR2                   0
#define ETHERNET_CONF_GATEWAY_ADDR3                   1
#define ETHERNET_CONF_NET_MASK0                       255
#define ETHERNET_CONF_NET_MASK1                       255
#define ETHERNET_CONF_NET_MASK2                       255
#define ETHERNET_CONF_NET_MASK3                       0
//Configure the PHY maintainance interface.
#define ETH_PHY_MODE                                  BOARD_EMAC_MODE_RMII
//Enable the system clock:
sysclk_init(); 
//Enable PIO configurations for EMAC:
board_init(); 
//Reset PHY; this is required by the DM9161A component:
rstc_set_external_reset(RSTC, 13);
rstc_reset_extern(RSTC);
while (rstc_get_status(RSTC) & RSTC_SR_NRSTL) {
};
//Wait for PHY ready:
ul_delay = sysclk_get_cpu_hz() / 1000 / 3 * 400;
while (ul_delay--);
//Enable PMC clock for EMAC:
pmc_enable_periph_clk(ID_EMAC); 
//Set the EMAC options; it's set to copy all frame and support broadcast:
emac_option.uc_copy_all_frame = 0;
emac_option.uc_no_boardcast = 0;
memcpy(emac_option.uc_mac_addr, gs_uc_mac_address, sizeof(gs_uc_mac_address));
gs_emac_dev.p_hw = EMAC;
//Initialize EMAC device with the filled option:
emac_dev_init(EMAC, &gs_emac_dev, &emac_option);
//Enable the interrupt service for EMAC:
NVIC_EnableIRQ(EMAC_IRQn);
//Initialize the PHY component:
ethernet_phy_init(EMAC, BOARD_EMAC_PHY_ADDR, sysclk_get_cpu_hz());
//The link will be established based on auto negotiation.
ethernet_phy_auto_negotiate(EMAC, BOARD_EMAC_PHY_ADDR);
//Establish the ethernet link; the network can be worked from now on:
ethernet_phy_set_link(EMAC, BOARD_EMAC_PHY_ADDR, 1);

//ADICIONAR AO MAIN LOOP -- COMANDO PARA INICIALIZAR A LEITURA DE DADOS DO ETHERNET
emac_dev_read(&gs_emac_dev, (uint8_t *) gs_uc_eth_buffer, sizeof(gs_uc_eth_buffer), &ul_frm_size));