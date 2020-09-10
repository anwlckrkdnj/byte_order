#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
	FILE* fp = NULL;
	uint32_t sum = 0;
	uint32_t value = 0; // read number from file

	for(int i = 1 ; i < argc ; i++){
		if((fp = fopen(argv[i], "r")) == NULL){
			printf("cant open %s\n", argv[i]);
			return 0;
		}

		fread(&value, sizeof(uint32_t), 1, fp);
		value = ntohl(value);
		printf("%d(%x)", value, value);
		sum += value;

		if(i < argc - 1)
			printf(" + ");

		fclose(fp);
	}

	printf(" = %d(%x)\n", sum, sum);
	
	return 0;
}
