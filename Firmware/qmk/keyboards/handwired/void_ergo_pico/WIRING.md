# Pinagem — VOID Ergo S com Raspberry Pi Pico

Esta é a pinagem usada pelos arquivos desta pasta. Ela vale para **as duas
metades** (a fiação é idêntica nas duas Picos).

## Matriz

| Função | GPIO | Pino físico da Pico |
|--------|------|---------------------|
| ROW0   | GP2  | 4                   |
| ROW1   | GP3  | 5                   |
| ROW2   | GP4  | 6                   |
| ROW3   | GP5  | 7                   |
| COL0   | GP6  | 9                   |
| COL1   | GP7  | 10                  |
| COL2   | GP8  | 11                  |
| COL3   | GP9  | 12                  |
| COL4   | GP10 | 14                  |
| COL5   | GP11 | 15                  |

Diodos na direção `COL2ROW`: ânodo (lado sem faixa) na coluna, cátodo (faixa)
na linha. As colunas são saídas e as linhas entradas, igual ao projeto original.

## Encoder

| Função | GPIO | Pino físico |
|--------|------|-------------|
| Encoder A | GP12 | 16 |
| Encoder B | GP13 | 17 |
| Comum     | GND  | qualquer GND |

Como a fiação é igual nas duas metades, não é necessário definir pinos
diferentes para o lado direito. Se a direção de rotação sair invertida em um
dos lados, troque A e B fisicamente (ou use `ENCODER_DIRECTION_FLIP`).

## Link serial entre as metades

| Sinal | GPIO | Pino físico |
|-------|------|-------------|
| Dados (half-duplex) | GP0 | 1 |
| GND | GND | qualquer GND |
| 5 V | VBUS (master) → VSYS (slave) | 40 → 39 |

O driver usado é o PIO (`SERIAL_DRIVER = vendor`), em half-duplex: um único fio
de dados. O PIO liga o pull-up interno, então **não precisa de resistor
externo**.

## Alimentação

- A metade master (a que tem USB) fornece 5 V pelo cabo: **VBUS (pino 40) do
  master → VSYS (pino 39) do slave**.
- **Nunca** ligue `3V3` de uma Pico na outra. O `VSYS` já passa pelo regulador
  e pelo diodo de cada placa.
- Como cada Pico tem diodo entre VBUS e VSYS, plugar USB nas duas ao mesmo tempo
  não injeta 5 V de uma na USB da outra.
- Prefira conectar/desconectar o cabo aux com o USB desligado (evita curto
  momentâneo entre contatos).

Com 4 condutores (TRRS/aux) sobram: 5 V, GND, dados e um fio reserva.

## USB e lado master

O QMK detecta o master pelo USB conectado. A metade com USB é tratada como
**esquerda**; portanto, plugue o USB na metade esquerda. Se quiser o USB na
direita, adicione `#define MASTER_RIGHT` no `config.h`.

## Entrar no bootloader

Qualquer uma das opções:

- Segurar BOOTSEL e plugar o USB;
- Dois toques rápidos no RUN (a LED GP25 pisca);
- Tecla `QK_BOOT` no keymap.

Depois é só copiar o `.uf2` gerado para a unidade `RPI-RP2`.

## Atenção: gabinete

A Pico mede aproximadamente 51 × 21 mm, enquanto o Pro Micro mede 33 × 18 mm.
O gabinete atual do VOID Ergo S foi desenhado para o Pro Micro, então a Pico
**não encaixa** no recorte existente e a saída do USB fica em outra posição.
Será necessário adaptar o case (ou usar um suporte/adaptador) antes da montagem
final.
