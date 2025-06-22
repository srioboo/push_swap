# push_swap

Project to learn about algorithms by sorting stacks of integers

Order two integers, you have two stack of values and a bunch of functions to manipulate both stacks.

You must create a C program that calculate and show a little protam with the instructions of the "Push Swap" lenguage, that order the numbers receibed as arguments.

Name: push_swap
archives: Makefile, '*.h', '*.c'
Makefile: NAME, all, clean, fclean, re
Arguments: stack a: a list of integers
Allowed functions:
    - read, write, malloc, free, exit
    - ft_printf and equivalente functions
Libft: yes
Description: order stacks

```shell
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```

## Sorting results and points

| Input Size | Average Operations | Maximum Operations allowed | Points |
|------------|--------------------|----------------------------|--------|
| 3          | 1-2                |                            | 3      |
| 5          | 5-10               |                            | 12     |
| 100        | 855-857            | <1300                      | 4/5    |
| 500        | 5739-5741          | <10000                     | 4/5    |

## Operations

Operations description and text write in the output once the operation is done

1. **swap**: swap the first 2 elements at the top of the stack a 
   - sa: swap a
   - sb: swap b
   - ss: swap a and b
2. **push**: takes the first element on top on list_b and puts in on list_a
   - pa: push a
   - pb: pusb b, same as previos opertation for b
3. **rotate**: swift elements one position, first element become last.
   - ra: rotate a, shift all the elements up ope position, firs element become last
   - rb: rotate b, same as previos for b
   - rr: rotate a and b
4. **rotate reverse**: swift elements one position, last element become first.
   - rra: reverse rotate, as rotate but in the other direction
   - rrb: reverse robate for b
   - rrr: reverse rotate all

## Test with checker

```shell
# count operations result
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# check result
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG

# check result with shuf
ARG=$(shuf -i 1-1000 -n 500); ./push_swap $ARG | ./checker_OS $ARG
```

## RADIX MSD

### Radix Sort MSD

Cuando trabajas con números enteros de longitud variable, el algoritmo Radix Sort MSD puede ser implementado de la siguiente manera:

1. **Identificación del Dígito Más Significativo:**
   - Determina el número máximo en la lista para saber cuántos dígitos tiene el número más largo. Esto te ayudará a saber cuántas iteraciones realizar.
2. **Uso de Dos Listas (o Stacks):**
   - Utiliza dos listas (o stacks) para distribuir los números según el dígito actual que estás procesando. Sin embargo, en el caso de números enteros, normalmente necesitarás 10 listas (una para cada dígito del 0 al 9) para manejar todos los posibles valores de dígitos.
3. **Distribución de Números:**
   - Para cada dígito, desde el más significativo hasta el menos significativo:- Recorre la lista de números y coloca cada número en la lista correspondiente según el dígito actual.
     - Por ejemplo, si estás en el primer dígito (más significativo), coloca los números en la lista correspondiente al valor de ese dígito.
4. **Recursividad:**
   - Después de distribuir los números en las listas, vacía la lista principal y luego aplica el mismo proceso recursivamente a cada lista, pasando al siguiente dígito menos significativo.
5. **Concatenación:**
   - Una vez que todos los dígitos han sido procesados, concatena las listas para obtener la lista ordenada final.

### Ejemplo de Implementación

Supongamos que tienes los siguientes números de longitud variable: 
```
[170, 45, 75, 90, 802, 24, 2, 66]
```

Paso a Paso;
1. **Determinar el número máximo:** El número más largo es 
   ```
   802
   ```

   , que tiene 3 dígitos.
2. **Iterar sobre los dígitos (de izquierda a derecha):**
   - **Dígito más significativo (hundreds):**
   - Distribuir en listas:

1. - - :- 0: \[802\]
       - 1: \[170\]
       - 2: \[2, 24\]
       - 4: \[45\]
       - 6: \[66\]
       - 7: \[75\]
       - 9: \[90\]
   - **Vaciar la lista principal y concatenar:**
   - Lista después de la primera pasada: ```
       [802, 170, 2, 24, 45, 66, 75, 90]
       ```
2. **Dígito del medio (tens):**
   - Distribuir en listas:
   - 0: \[2, 24\]
     - 1: \[170\]
     - 2: \[\]
     - 4: \[45\]
     - 6: \[66\]
     - 7: \[75\]
     - 8: \[802\]
     - 9: \[90\]
   - **Vaciar la lista principal y concatenar:**
   - Lista después de la segunda pasada: ```
       [2, 24, 45, 66, 75, 90, 170, 802]
       ```
3. **Dígito menos significativo (units):**
   - Distribuir en listas:
   - 0: \[170\]
     - 2: \[2\]
     - 4: \[24\]
     - 5: \[75\]
     - 6: \[66\]
     - 7: \[\]
     - 8: \[802\]
     - 9: \[90\]
   - **Vaciar la lista principal y concatenar:**
   - Lista final ordenada: ```
       [2, 24, 45, 66, 75, 90, 170, 802]
       ```

### Resumen

- **Radix Sort MSD** es un algoritmo eficiente para ordenar números enteros de longitud variable.
- Utiliza listas para distribuir los números según los dígitos, comenzando desde el más significativo.
- La recursividad y la concatenación de listas permiten obtener la lista ordenada final.

Si necesitas un ejemplo de código en un lenguaje específico o más detalles sobre la implementación, no dudes en decírmelo.


### Resources

- https://push-swap42-visualizer.vercel.app/
- gmartin tester push_swap https://github.com/gemartin99/Push-Swap-Tester?tab=readme-ov-file
- https://github.com/ailopez-o/42Barcelona-PushSwap-ProChecker (visualizer)
- https://pinetools.com/es/generador-numeros-aleatorios

