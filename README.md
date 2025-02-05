# Semáforo leds

## Estrutura do Projeto  
- **build/** → Diretório de compilação gerado pelo CMake.  
- **diagram.json** → Simulação do Wokwi 
- **CMakeLists.txt** → Configuração do CMake para compilação.  
- **Semaforo.c** → Código principal do projeto.    
- **pico_sdk_import.cmake** → Importação do SDK do Raspberry Pi Pico.  
- **README.md** → Documentação do projeto.  
- **Semaforo_RGB** → Documento em txt com o codigo para usar na placa , misturando os leds vermelho com azul (amarelo), GPIO 13 e 11.

## Descrição Geral
 Este projeto visa simular o funcionamento de um semáforo 
 utilizando LEDs, com temporização de 3 segundos para cada
mudança de sinal. O sistema inicia com o sinal vermelho 
aceso, alterna para o sinal amarelo, e, em seguida, para o 
sinal verde. As mudanças de estado dos LEDs ocorrem com um intervalo 
de 3 segundos, e essa lógica é controlada por um temporizador configurado 
para disparar a cada 3.000 ms. A principal funcionalidade do projeto 
é demonstrar a alternância dos LEDs utilizando temporizadores e funções 
de callback, com interação por um botão.

 

## Video do funcionamento do projeto usando o led RGB e GPIO 12 
https://drive.google.com/file/d/1hIG8jx_iI1Uijh_XgKumP72KiHPIL_Fe/view?usp=sharingg

## Video do funcionamento do projeto usando a mistura do RGB GPIO 11 e 13
https://drive.google.com/file/d/1hFvHJdBVumI_FLqVhMKsY6Kh4CNnfYm6/view?usp=drive_link

## Video do funcionamento no simulador dentro do vscode com GPIO 12 
https://drive.google.com/file/d/1xbVxYecFbzsi63KqMtRlpHYz-4fz1_2y/view?usp=sharing

## Video do funcionamento no simulador dentro do vscode com GPIO 11 e 13
https://drive.google.com/file/d/13pP_0ThIzlzZgzseRZ6ZozHRleIOc3X8/view?usp=sharing

## Componentes Utilizados:
- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (vermelho, amarelo e verde)
- 03 Resistores de 330Ω

## Fluxograma Simplificado
O fluxograma básico do semáforo segue a sequência de estados ilustrada na figura abaixo:

1.  Estado inicial: LED vermelho aceso
2. Após 3 segundos: LED amarelo aceso
3. Após mais 3 segundos: LED verde aceso
4. Repetição do ciclo, começando novamente com o LED vermelho.
A alternância dos LEDs é realizada de forma sequencial, com um ciclo completo durando 9 segundos (3 segundos por estado).

## Funcionalidades do Projeto
1. Controle dos LEDs
- O sistema inicia com o sinal vermelho aceso.
- Após 3 segundos, o LED amarelo acende, e o vermelho é desligado.
- Após mais 3 segundos, o LED verde acende, e o amarelo é desligado.
- A sequência repete-se continuamente.

2. Temporizador (Repetindo a cada 3 segundos)
O temporizador é configurado para disparar a cada 3.000 ms (3 segundos), acionando uma função de callback que altera o estado dos LEDs.

3. Sequência de LEDs
Inicialmente, todos os LEDs estão apagados.
Os LEDs começam a alternar de acordo com o temporizador.
A sequência continua com o sinal vermelho, seguido do amarelo e do verde, em ciclos de 3 segundos.

4. Exibição de Mensagens na Serial
A rotina principal imprime mensagens na porta serial a cada 1 segundo (1.000 ms), proporcionando feedback sobre o estado atual do sistema, como o número de ciclos de LEDs completados.

## Requisitos do Projeto
- Inicialização com todos os LEDs apagados.
- Sequência de LEDs:
   - Estado 1: Todos os LEDs acesos.
   - Estado 2: Dois LEDs acesos, um apagado.
   - Estado 3: Apenas um LED aceso, dois apagados.
- Temporização: Cada mudança de estado ocorre a cada 3 segundos, utilizando um temporizador.

## Configuração do Ambiente

1. Instalação do SDK do Raspberry Pi Pico
Para configurar o ambiente de desenvolvimento, siga as instruções de instalação do SDK do Raspberry Pi Pico, incluindo a configuração do Visual Studio Code com as extensões apropriadas para compilar e carregar o código no microcontrolador.

2. Clone o Repositório
Clone o repositório com o código-fonte do projeto:
git clone: https://github.com/alinnecaastro/temporizador_one_shot.git

3. Compilação do Projeto
Para compilar o projeto, abra o Visual Studio Code e siga os seguintes passos:

- Clean CMake – Para garantir que o projeto seja compilado a partir do zero.
- Compile Project – Para compilar o código-fonte e gerar o binário.
- Run Project [USB] – Para carregar o código no Raspberry Pi Pico W via USB.

4. Carregue o Firmware no Raspberry Pi Pico W
Conecte o Raspberry Pi Pico W ao computador e faça o upload do firmware gerado para a placa.


## Funcionamento do Código

1. Inicialização
O código começa configurando os pinos GPIO 11, 12 e 13 para controlar os LEDs. O estado inicial é com todos os LEDs apagados.

2. Sequência de LEDs
A sequência de LEDs é gerenciada pela função de callback do temporizador. Após 3 segundos de cada transição, a função altera o estado dos LEDs, seguindo a ordem: vermelho → amarelo → verde → todos apagados. A sequência só pode ser reiniciada após a mudança de estado completo.

3. Temporizador e Funções de Callback
A função add_repeating_timer_ms() é utilizada para configurar um temporizador que aciona a função de callback a cada 3 segundos. Dentro dessa função de callback, o estado dos LEDs é alterado sequencialmente.

4. Exibição de Informações na Serial
A rotina principal do código imprime informações na serial a cada 1 segundo, para fornecer feedback sobre o andamento da sequência de LEDs.

## Conclusão
O código implementado permite controlar a sequência de LEDs (vermelho, amarelo e verde) 
com um temporizador de 3 segundos. O temporizador garante que os LEDs alterem seus 
estados de forma sequencial e cíclica, Este projeto demonstra o uso de temporizadores e controle 
de dispositivos eletrônicos básicos com o Raspberry Pi Pico W.