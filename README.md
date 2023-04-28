# Algoritmo de Luhn
>O algoritmo de Luhn é um algoritmo que verificão se o cartão de crédito é válido ou não.

<br><strong>
O algoritimo funciona da seguinte maneira:
</strong></br>

1. Começando com o penúltimo dígito e movendo para a esquerda, multiplique por 2 o valor de todos os dígitos de maneira intercalada.
2. Pegue os digitos que não foram multiplicados e some com todos os resultados da primeira parte. Caso o produto da multiplicação anterior tenha 2 digitos,
some os 2 (Resultado da primeira etapa 16, faça 1 + 6).
3. Ao final da soma, o número apresentado deverá ter final 0. Caso contrário o número do cartão é inválido.

Exemplo:
<div align="center">
<img src="https://user-images.githubusercontent.com/121034187/235030750-5b3abb5c-fc68-4b79-9978-9c05e70425bc.png" width="750px" />
</div>
<strong>
Como saber qual a companhia do cartão:
</strong>

Cada operadora tem um código deixado no inicio do cartão.


<div align="center">
<img src="https://user-images.githubusercontent.com/121034187/235024649-d828090c-b367-45d2-ae8f-eba9bce31e68.png" width="500px" />
</div>

<strong><br>
Meu programa:
</strong></br>
O meu programa tem como objetivo descobrir qual a companhia o cartão opera (VISA, MASTERCARD ou AMEX) e se ele é valido ou não.



> Para aprofundamento no tema:

https://en.wikipedia.org/wiki/Luhn_algorithm
