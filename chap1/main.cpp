#include <stdio.h>
#include <string.h>

char *search(char *str, char* key);
int input(char *buff, int size);

int main(void) {
	char str[] = "abcdefghijklmnopqrstuvwxyz";
	char key[21];
	char *p;
	int i;

	input(key, sizeof(key)); // キーボードから入力
	if((p = search(str, key)) != NULL) {
		for(i = 0; str[i] != '\0'; i++) {
			if(&str[i] == p) {
				printf("*");
			}
			printf("%c", str[i]);
		}
		printf("\n");
	} else {
		printf("%s\n", str);
		printf("見つからない\n");
	}
}

char *search(char *str, char* key) {
	int n = strlen(str);
	int m = strlen(key);
	char *p;

	for(p = str; p + m <= str + n  && strncmp(p, key, m) != 0; p++) {
		if(p + m > str + n) {
			p = NULL;
		}
	}

	return p;

} 

int input(char *buff, int size) {
	size_t n;

	printf("探索したい文字列を入力:");
	fgets(buff, size, stdin);

	printf("%p\n", buff);
	printf("%c\n", *buff);
	
	n = strlen(buff);
	printf("%d\n", *(buff + n - 1));

	if(*(buff + n - 1) == '\n') {
		*(buff + n - 1) = '\0';
		n--;
	}

	return n;
	
}