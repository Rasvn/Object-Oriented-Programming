#pragma GCC optimize ("O3")
#pragma warning (disable:4996)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define lmax 10000

typedef int huge[2 * lmax + 3];

/*
* Ii atribuie unui numar mare valoarea unui string
* h - huge number, s - string
* h[0] lungimea numarului din s, h[1..n] valoarea inversa a numarului din s
*/
void atribValue(huge h, char* s);

/*
* Ii atribuie unui numar mare valoarea altui numar mare
* h, x - huge numbers
* h va avea valoarea lui x
*/
void atribHuge(huge h, huge x);

/*
* Afiseaza un numar mare
* h - huge number
* print on screen the number
*/
void afisHuge(huge h);

/*
* Compara 2 numere mari.
* h, x - huge numbers
* return -1 daca h < x, +1 daca h > x, 0 daca h == x
*/
short sgn(huge h, huge x);

/*
* Aduna 2 numere mari.
* a, b - huge numbers
* a va avea valoarea lui a + b
*/
void add(huge a, huge b);

/*
* Scade 2 numere mari
* a, b - huge numbers
* a va avea valoarea lui a - b
*/
void sub(huge a, huge b);

/*
* Face inmultirea dintre un vector si un scalar
* h - huge number, x - unsigned integer
* h va avea valoarea lui h * x
*/
void mul(huge h, unsigned int x);

/*
* Shifteaza vectorul cu un numar de pozitii la stanga
* h - huge number, Count - unsigned integer
* h va avea valoarea vectorului shiftat
*/
void shl(huge h, unsigned int Count);

/*
* Shifteaza vectorul cu un numar de pozitii la dreapta
* h - huge number, Count - unsigned integer
* h va avea valoarea vectorului shiftat
*/
void shr(huge h, unsigned int Count);

/*
* Face radicalul unui numar gigantic h
* h, ans - huge number
* ans <- sqrt(h)
*/
void sqrt_huge(huge h, huge ans);

int main(int argc, char** argv) {
	char s[lmax], * real_s, * imag_s, new_s[lmax];
	int prec, continua = 1;
	while (continua) {
		printf(" Numarul: ");
		scanf("%s", s);
		printf(" Precizie: ");
		scanf("%d", &prec);
		int initial_value = strlen(s);
		real_s = strtok(s, ".");
		if (strlen(s) == initial_value) {
			for (int i = 1; i <= prec; ++i) {
				strcat(s, "00");
			}
			huge real, ans, extra;
			atribValue(real, s);
			sqrt_huge(real, ans);
			printf("Radicalul cu %d decimale: ", prec);
			for (int i = ans[0]; i > prec; --i) {
				printf("%d", ans[i]);
			}
			printf(".");
			for (int i = prec; i > 0; --i) {
				printf("%d", ans[i]);
			}
			printf("\n");
		}
		else {
			imag_s = strtok(NULL, ".");
			strcpy(new_s, real_s);
			if (strlen(imag_s) >= 2 * prec) {
				strncat(new_s, imag_s, 2 * prec);
			}
			else {
				strcat(new_s, imag_s);
				for (int i = strlen(imag_s); i < 2 * prec; ++i) {
					strcat(new_s, "0");
				}
			}
			huge real, ans, extra;
			atribValue(real, new_s);
			sqrt_huge(real, ans);
			printf("Radicalul cu %d decimale: ", prec);
			for (int i = ans[0]; i > prec; --i) {
				printf("%d", ans[i]);
			}
			printf(".");
			for (int i = prec; i > 0; --i) {
				printf("%d", ans[i]);
			}
			printf("\n");

		}
		printf(" Doriti sa continuati? (1 - DA, 0 - NU): ");
		scanf("%d", &continua);
	}

	return 0;
}



void atribValue(huge h, char* s) {
	h[0] = 0;
	for (int i = strlen(s) - 1; i > -1; --i) {
		++h[0];
		h[h[0]] = s[i] - '0';
	}
	while (h[0] && !h[h[0]]) h[0]--;
}

void atribHuge(huge h, huge x) {
	for (int i = 0; i <= x[0]; ++i) {
		h[i] = x[i];
	}
}

void afisHuge(huge h) {
	if (h[0] == 0) printf("0");
	for (int i = h[0]; i >= 1; --i) {
		printf("%d", h[i]);
	}
	printf("\n");
}

short sgn(huge h, huge x) {
	while (h[0] && !h[h[0]]) h[0]--;
	while (x[0] && !x[x[0]]) x[0]--;

	if (h[0] < x[0]) {
		return -1;
	}
	if (h[0] > x[0]) {
		return +1;
	}

	for (int i = h[0]; i > 0; --i) {
		if (h[i] < x[i]) {
			return -1;
		}
		if (h[i] > x[i]) {
			return +1;
		}
	}

	return 0;
}

void add(huge a, huge b) {
	if (b[0] > a[0]) {
		for (int i = a[0] + 1; i <= b[0]; ++i) {
			a[i] = 0;
			++a[0];
		}
	}
	else {
		for (int i = b[0] + 1; i <= a[0]; ++i) {
			b[i] = 0;
		}
	}
	bool transp = 0;
	for (int i = 1; i <= a[0]; ++i) {
		a[i] += b[i] + transp;
		transp = a[i] / 10;
		a[i] %= 10;
	}
	if (transp) {
		a[++a[0]] = transp;
	}
}

void sub(huge a, huge b) {
	bool transp = 0;
	for (int i = b[0] + 1; i <= a[0]; ++i) {
		b[i] = 0;
	}
	for (int i = 1; i <= a[0]; ++i) {
		a[i] -= b[i] + transp;
		if (a[i] < 0) transp = 1;
		else transp = 0;
		if (transp) a[i] += 10;
	}
	while (a[0] && !a[a[0]]) {
		--a[0];
	}
}

void mul(huge h, unsigned int x) {
	unsigned long transp = 0;
	for (int i = 1; i <= h[0]; ++i) {
		h[i] = h[i] * x + transp;
		transp = h[i] / 10;
		h[i] = h[i] % 10;
	}
	while (transp) {
		h[++h[0]] = transp % 10;
		transp /= 10;
	}
}

void shl(huge h, unsigned int Count) {
	for (int i = h[0]; i > 0; --i) {
		h[i + Count] = h[i];
	}
	for (int i = 1; i <= Count; ++i) {
		h[i] = 0;
	}
	h[0] += Count;
}

void shr(huge h, unsigned int Count) {
	for (int i = Count + 1; i <= h[0]; ++i) {
		h[i - Count] = h[i];
	}
	h[0] -= Count;
}

void sqrt_huge(huge h, huge ans) {
	if (h[0] & 1) {
		++h[0];
		h[h[0]] = 0;
	}
	huge transp, curent, pair, zero;
	atribValue(zero, "0");
	atribValue(transp, "0");
	atribValue(ans, "0");
	for (int i = h[0]; i > 0; i -= 2) {
		atribHuge(curent, ans);
		mul(curent, 2);
		mul(transp, 100);
		char s[3];
		s[0] = h[i] + '0';
		s[1] = h[i - 1] + '0';
		s[2] = '\0';
		huge pair, aux;
		atribValue(pair, s);
		add(transp, pair);
		shl(curent, 1);
		int next_value = 0;
		for (int i = 0; i <= 9; ++i) {
			atribHuge(aux, curent);
			aux[1] = i;
			mul(aux, i);
			if (sgn(aux, transp) == 1)
				break;
			next_value = i;
		}
		curent[1] = next_value;
		mul(curent, next_value);
		mul(ans, 10);
		if (ans[0] == 0) {
			ans[0] = 1;
		}
		ans[1] = next_value;
		sub(transp, curent);
	}
}
