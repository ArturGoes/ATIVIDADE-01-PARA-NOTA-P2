#include <stdio.h>
#include <limits.h>
int calcular_mdc(int a, int b) {
while (b != 0) {
int temp = b;
b = a % b;
a = temp;
}
return a;
}
int calcular_mmc(int a, int b) {
if (a == 0 || b == 0) {
return 0;
}
int mdc = calcular_mdc(a, b);
if ((a / mdc) > (INT_MAX / b)) {
return -1;
}
return (a / mdc) * b;
}
void tabela_adicao_modular(int n) {
if (n <= 0) {
printf("Erro: n deve ser positivo.\n");
return;
}
printf("\nTabela de Adicao Modular Z_%d:\n", n);
printf(" |");
for (int i = 0; i < n; i++)
printf("%3d", i);
printf("\n");
printf("----");
for (int i = 0; i < n; i++)
printf("---");
printf("\n");
for (int i = 0; i < n; i++) {
printf("%3d|", i);
for (int j = 0; j < n; j++) {
printf("%3d", (i + j) % n);
}
printf("\n");
}
}
void tabela_multiplicacao_modular(int n) {
if (n <= 0) {
printf("Erro: n deve ser positivo.\n");
return;
}
printf("\nTabela de Multiplicacao Modular Z_%d:\n", n);
printf(" |");
for (int i = 0; i < n; i++)
printf("%3d", i);
printf("\n");
printf("----");
for (int i = 0; i < n; i++)
printf("---");
printf("\n");
for (int i = 0; i < n; i++) {
printf("%3d|", i);
for (int j = 0; j < n; j++) {
printf("%3d", (i * j) % n);
}
printf("\n");
}
}
int main() {
int a, b, n;
printf("Digite o valor de a: ");
scanf("%d", &a);
printf("Digite o valor de b: ");
scanf("%d", &b);
printf("Digite o valor de n (para as tabelas modulares): ");
scanf("%d", &n);
int mdc = calcular_mdc(a, b);
int mmc = calcular_mmc(a, b);
printf("\nMDC(%d, %d) = %d\n", a, b, mdc);
if (mmc == -1) {
printf("MMC(%d, %d) causa overflow\n", a,b);
}
else {
printf("MMC(%d, %d) = %d\n", a, b, mmc);
}
tabela_adicao_modular(n);
tabela_multiplicacao_modular(n);
return 0;
}