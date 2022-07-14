#include <stdint.h>

void Reset_handler();
extern int main(void);

void Default_handler(){
	Reset_handler();
}
void NMI_handler() __attribute__((weak, alias("Default_handler")));;
void H_fault_handler() __attribute__((weak,alias("Default_handler")));;

static unsigned long Stack_top[256];

void (* const g_p_fn_vectors[])() __attribute__((section(".vectors")))=
{
	(void (*)()) ((unsigned long)Stack_top + sizeof(Stack_top)),&Reset_handler,&NMI_handler,&H_fault_handler
};

extern unsigned int _E_text;
extern unsigned int _s_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void Reset_handler(){
	unsigned int Data_size = (unsigned char *) &_E_data - (unsigned char *)&_s_data;
	unsigned char* p_src= (unsigned char *)&_E_text;
	unsigned char* p_dst=(unsigned char *)&_s_data;
	for (int i=0;i<Data_size;i++){
		*((unsigned char*)p_dst++) = *((unsigned char *)p_src++);
	}

	unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
	p_dst=(unsigned char *)&_S_bss;
	for(int i=0; i<bss_size;i++){
		*((unsigned char *) p_dst++)=(unsigned char)0;
	}
	main();
}