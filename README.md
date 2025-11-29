# estrutura-de-dados-trabalho-2-banco
# 🏦 Sistema de Filas Bancárias em C

## 🎯 Objetivo Geral
Desenvolver, em grupos, uma aplicação em **linguagem C** que utilize filas lineares (estáticas ou dinâmicas, com ou sem prioridade, e com opção circular) de forma funcional, simulando o atendimento em duas filas de caixa (normal e rápido), com controle de entrada, atendimento e registro de histórico. O foco está em integrar teoria e prática, aplicando conceitos de filas em contextos reais e relevantes.

---

## 🧩 Cenário-Problema
Uma agência bancária deseja informatizar o sistema de controle de **duas filas simultâneas de atendimento**:

- 🟦 **Fila Comum** — para qualquer cliente  
- 🟩 **Fila Rápida** — para clientes com **menos de 2 procedimentos**

Os atendimentos acontecem **em paralelo**, alternando entre os caixas.  
A cada atendimento, o sistema registra:

- Cliente atendido  
- Tempo estimado de atendimento  
- Caixa responsável (Comum ou Rápido)

Ao final do dia, o sistema gera **estatísticas de desempenho**, como:

- ⏱️ Tempo médio de atendimento por fila  
- 👥 Total de clientes atendidos por caixa  

---

## ⚙️ Funcionalidades Mínimas Obrigatórias

🧍‍♂️ **Cadastrar cliente** (nome, número, quantidade de procedimentos)  
➡️ **Inserir cliente na fila correta** (rápida ou comum)  
🔄 **Atender clientes alternando entre caixas**  
🗂️ **Registrar cada atendimento em uma pilha de histórico**  
📋 **Exibir a fila atual de cada caixa**  
⏱️ **Calcular tempo médio por tipo de fila**  
📜 **Listar todos os atendimentos realizados**, com nome, tipo e tempo

---

## 💻 Como Usar

### 🧱 Executar o programa
Baixe o arquivo **main.exe** e utilize o teclado para navegar pelas opções do menu.

### 🧰 Compilar o código manualmente
Caso deseje modificar o código-fonte, recompile utilizando **GCC**:

```bash
gcc main.c clientes.c fila.c atendimento.c historico.c -o main
