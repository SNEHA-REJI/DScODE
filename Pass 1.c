#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
printf("Name:Kesiya Mariam Reji\tBranch:CS-B\tRoll no.:54\n");
    int start_addr = 0, locctr = 0, length = 0;
    char label[30], opcode[30], operand[30];
    FILE *input_ptr, *optab_ptr, *symtab_ptr, *intermediate_ptr, *size_ptr;
input_ptr = fopen("input.txt", "r");
    symtab_ptr = fopen("symtab.txt", "w");
    intermediate_ptr = fopen("intermediatefile.txt", "w");
    size_ptr = fopen("prgsize.txt", "w");
if (input_ptr == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }
while (fscanf(input_ptr, "%s %s %s", label, opcode, operand) != EOF)
    {
        if (strcmp(opcode, "START") == 0)
        {
            char *endptr;
            start_addr = (int)strtol(operand, &endptr, 16);  
            if (*endptr != '\0')
            {
                printf("Error: Invalid start address. '%s' is not a valid hexadecimal number.\n", operand);
                fclose(input_ptr);
                fclose(symtab_ptr);
                fclose(intermediate_ptr);
                fclose(size_ptr);
                return 1;
            }
            locctr = start_addr;
            length = 0;
            fprintf(intermediate_ptr, "\t   %s %s %s\n", label, opcode, operand);
        }
        else if (strcmp(opcode, "END") == 0)
        {
        length=3;
            fprintf(intermediate_ptr, "\t %d %s %s %s\n",length, label, opcode, operand);
            fprintf(size_ptr, "%04X", locctr - start_addr);  // Program size in hex
            break;  // Stop processing after END is encountered
        }
        else
        {
            if (strcmp(label, "-") != 0)
            {
            symtab_ptr = fopen("symtab.txt", "a");
            char symtab_label[30];
        int symtab_addr,flag1=0;
rewind(symtab_ptr);
    while (fscanf(symtab_ptr, "%s %x", symtab_label, &symtab_addr) != EOF)
    {
        if (strcmp(symtab_label,label) == 0)
        {
            flag1=1;
            break;
        }
        }
        if(flag1==0)
                fprintf(symtab_ptr, "%s %X\n", label, locctr);  
            }
int is_format_4 = 0;
            if (opcode[0] == '+')
            {
                is_format_4 = 1;
                memmove(opcode, opcode + 1, strlen(opcode));
            }

            if (strcmp(opcode, "BYTE") == 0)
            {
                if (operand[0] == 'X')
                    length = (strlen(operand) - 3) / 2;
                if (operand[0] == 'C')
                    length = strlen(operand) - 3;
            }
            else if (strcmp(opcode, "WORD") == 0)
            {
                length = 3;
            }
            else if (strcmp(opcode, "RESB") == 0)
            {
                length = (int)strtol(operand, NULL, 10);
            }
            else if (strcmp(opcode, "RESW") == 0)
            {
                length = 3 * (int)strtol(operand, NULL, 10);
            }
            else
            {
                char op[20], hex_value[10];
                int flag = 0;
                optab_ptr = fopen("OPTAB.txt", "r");
                while (fscanf(optab_ptr, "%s %s", op, hex_value) != EOF)
                {
                    if (strcmp(opcode, op) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                fclose(optab_ptr);
                if (flag == 0)
                {
                    printf("Error: Invalid opcode '%s'. Terminating program.\n", opcode);
                    fclose(input_ptr);
                    fclose(symtab_ptr);
                    fclose(intermediate_ptr);
                    fclose(size_ptr);
                    return 1;
                }
                length = is_format_4 ? 4 : 3;
            }
            fprintf(intermediate_ptr, "%X %d %s %s %s\n", locctr, length, label, opcode, operand);
            locctr += length;
        }
    }
    fclose(input_ptr);
    fclose(symtab_ptr);
    fclose(intermediate_ptr);
    fclose(size_ptr);
printf("EXIT PASS1\n");
    return 0;
}