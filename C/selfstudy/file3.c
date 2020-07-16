#include <stdio.h>
#include <stdlib.h>
struct name{
	char surname[16];
	char givenname[32];
};

struct phone{
	int first;
	int last;
};

struct info{
	struct name n;
	struct phone p;
};

int main(void){
	int i;
	struct info foo[3] = {{{"David", "Park"},{111,2222}},{{"Jane", "Kim"},{123,3332}},{{"Sally", "Lee"},{555,4847}} }, bar[3];
	
	FILE *fp1 = 0, *fp2 = 0;
	fp1 = fopen("data.txt", "w");

	fwrite(foo, sizeof(struct info), 3, fp1);
	fclose(fp1);

	fp2 = fopen("data.txt", "r");
	fread(bar, sizeof(struct info), 3, fp2);
	fclose(fp2);
	
	for(i = 0; i < 3; i++)	printf("%s %s : %d-%d\n", bar[i].n.surname, bar[i].n.givenname, bar[i].p.first, bar[i].p.last);
	
	return 0;
}
