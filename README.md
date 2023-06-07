[![Build Status][ot-rtos-travis-svg]][ot-rtos-travis]

[ot-rtos-travis]: https://travis-ci.org/openthread/ot-rtos
[ot-rtos-travis-svg]: https://travis-ci.org/openthread/ot-rtos.svg?branch=main

---
# ELC1048 - PROJETO DE SISTEMAS EMBARCADOS
# Projeto final
## Especificação do projeto final:
Objetivo: Desenvolvimento de uma aplicação de rede de sensores sem fio (IoT) com base no projeto OpenThread (equipe APP) e portabilidade do projeto para a plataforma SAM R21 Xplorer Pro (equipe HAL).

## Organização e requisitos do projeto
•  Duas equipes de projeto (APP ou HAL, 8 integrantes cada).
• Cada equipe deve montar um cronograma de desenvolvimento com divisão de tarefas
(contribuições individuais ou em duplas – pair programming).
• Repositórios de cada equipe no github.com
O projeto deverá ser:
1. Mantido em repositório no GitHub.
2. Organizado e implementado como um sistema multitarefas (OpenThread RTOS).

## Missão da equipe HAL
1. Realizar a portabilidade do projeto OpenThread RTOS (OTRTOS) que utiliza FreeRTOS, LwIP para o HW do laboratório (SAM R21 e SAM D21 Xplorer Pro).
2. Realizar os testes necessitados pela equipe de APP para rodar a aplicação na plataforma de HW e no OT-RTOS.
3. Realizar a demonstração do projeto e documentar os passos necessários para portar a aplicação: como compilar, usar, testar e executar a demonstração.

## Requisitos funcionais – equipe HAL
O sistema deve permitir o monitoramento:
1. Do estado da rede. (conectado/desconectado)
2. Da conexão dos dispositivos.
3. Da taxa de entrega das mensagens.

## Tabela de materiais
- Placas de desenvolvimento:
- Disponíveis no Laboratório:
- ARM SAM D21 ou SAM R21 Xplorer Pro
- Opcionalmente, Arduinos
- Ou outras quaisquer, como:
- ESP32, Raspberry Pi, etc
## Tabela de materiais sugeridos:
Para auxiliar no desenvolvimento extra-classe sugere-se o uso de simulador.
- Simulador IAR EW ARM, MPLAB, etc.
- Simulador OpenThread (em Linux, MAC OS, Windows/Docker).
OpenThread Network Simulator (OTNS): https://openthread.io/platforms/simulation?hl=pt-br

## Entrega
1) Relatório final em pdf – 20%
2) Projeto com código-fonte (link do repositório do GitHub.com). Licença: código-aberto/open-source MIT - 30% (contribuições individuais ou em duplas, conforme relatório do github)
3) Documentação pdf do código-fonte (gerado com Doxygen) – 10%
4) Apresentação em ppt ou vídeo – 40% (haverá perguntas individuais)

## Prazo
• Até a última semana do semestre (antes da semana de exames finais).
• Acompanhamento semanal (terças-feiras).
• Execução no laboratório (quintas-feiras).
• Anotações compartilhadas em: https://docs.google.com/document/d/1wH1syYwm5gm5lCkSNSCq9IpZZ0ZUaTe_Ln4mlxfcBb4/edit?usp=sharing

# OpenThread RTOS
The OpenThread RTOS project provides an integration of:
1. [OpenThread](https://github.com/openthread/openthread), an open-source implementation of the Thread networking protocol.
2. [LwIP](https://git.savannah.nongnu.org/git/lwip/lwip-contrib.git/), a small independent implementation of the TCP/IP protocol suite.
3. [FreeRTOS](https://www.freertos.org/), a real time operating system for microcontrollers.

OpenThread RTOS includes a number of application-layer demonstrations, including:
- [MQTT](http://mqtt.org/), a machine-to-machine (M2M)/"Internet of Things" connectivity protocol.
- [HTTP](https://en.wikipedia.org/wiki/Hypertext_Transfer_Protocol), the underlying protocol used by the World Wide Web.
- [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol), one of the main transport protocols in the Internet protocol suite.

## Getting started
### Linux simulation

```sh
git submodule update --init
mkdir build && cd build
cmake .. -DPLATFORM_NAME=linux
make -j12
```

This will build the CLI test application in `build/ot_cli_linux`.

### Nordic nRF52840

```sh
git submodule update --init
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-none-eabi.cmake -DPLATFORM_NAME=nrf52
make -j12
```

This will build the CLI test application in `build/ot_cli_nrf52840.hex`. You can flash the binary with `nrfjprog`([Download](https://www.nordicsemi.com/Software-and-Tools/Development-Tools/nRF5-Command-Line-Tools)) and connecting to the nRF52840 DK serial port. This will also build the demo application in `build/ot_demo_101`. See the [Demo 101 README](examples/apps/demo_101/README.md) for a description of the demo application.

# Contributing

We would love for you to contribute to OpenThread RTOS and help make it even better than it is today! See our [Contributing Guidelines](https://github.com/openthread/ot-rtos/blob/main/CONTRIBUTING.md) for more information.

Contributors are required to abide by our [Code of Conduct](https://github.com/openthread/ot-rtos/blob/main/CODE_OF_CONDUCT.md) and [Coding Conventions and Style Guide](https://github.com/openthread/ot-rtos/blob/main/STYLE_GUIDE.md).

We follow the philosophy of [Scripts to Rule Them All](https://github.com/github/scripts-to-rule-them-all).

# License

OpenThread RTOS is released under the [BSD 3-Clause license](https://github.com/openthread/ot-rtos/blob/main/LICENSE). See the [`LICENSE`](https://github.com/openthread/ot-rtos/blob/main/LICENSE) file for more information.

Please only use the OpenThread name and marks when accurately referencing this software distribution. Do not use the marks in a way that suggests you are endorsed by or otherwise affiliated with Nest, Google, or The Thread Group.

# Need help?

OpenThread support is available on GitHub:

- OpenThread RTOS bugs and feature requests — [submit to the openthread/ot-rtos Issue Tracker](https://github.com/openthread/ot-rtos/issues)
- OpenThread bugs and feature requests — [submit to the OpenThread Issue Tracker](https://github.com/openthread/openthread/issues)
- Community Discussion - [ask questions, share ideas, and engage with other community members](https://github.com/openthread/openthread/discussions)

## OpenThread

To learn more about OpenThread, see the [OpenThread repository](https://github.com/openthread/openthread).
