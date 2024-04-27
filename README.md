# <p align = center>Minitalk</p>
<div align = center>
  <img src="https://media.licdn.com/dms/image/D4D22AQHZ7EdiIb8ngQ/feedshare-shrink_800/0/1710943432968?e=1717027200&v=beta&t=4S-5bC9B-H6orVnggcTHauCJUc-j3tbKWRvohuaGeqE">
</div>

#

Minitalk é um projeto em C que implementa uma comunicação simples entre processos utilizando sinais do sistema UNIX. Ele consiste em dois programas: um cliente (client) que envia mensagens e um servidor (server) que as recebe.

## Funcionalidades

O projeto Minitalk utiliza as seguintes funções e conceitos:

- `ft_printf`: Função personalizada para formatação de strings.
- `signal`: Função para configurar manipuladores de sinais.
- `kill`: Função para enviar sinais para processos.
- `getpid`: Função para obter o PID (identificador de processo) do processo atual.
- `malloc` e `free`: Funções para alocação e liberação de memória dinâmica.
- `usleep`: Função para suspender a execução do programa por um determinado número de microssegundos.
- `exit`: Função para terminar a execução de um programa.

O cliente envia mensagens ao servidor enviando sinais de usuário (`SIGUSR1` e `SIGUSR2`) para o processo do servidor. Cada caractere da mensagem é enviado como uma sequência de bits, onde o servidor interpreta os sinais recebidos para reconstruir a mensagem.

## Compilando e Executando

Para compilar o projeto, você pode usar o Makefile fornecido. Basta executar o comando `make` no terminal no diretório do projeto. Isso irá compilar o código fonte e criar os executáveis `client` e `server`.

### Executando o Servidor

```bash
./server
```
#
O servidor será iniciado e mostrará o PID do processo em que está sendo executado. Ele ficará aguardando as mensagens enviadas pelo cliente.
#
### Executando o Cliente

```bash
./client [PID_do_Servidor] [Mensagem]
```
Substitua [PID_do_Servidor] pelo PID mostrado quando o servidor foi iniciado e [Mensagem] pela mensagem que deseja enviar.
