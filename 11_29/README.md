# Appunti

## Debugger (GDB)
- Installa GDB
Sostituisci `${nome_file}` con il nome del file **.c** .
Sostituisci `${nome_exec}` con il nome dell'**eseguibile**.

```sh
gcc -g ${nome_file}.c -o ${nome_exec}
gdb --args ./${nome_exec}
```

| Comando | Risultato |
| ------ | ------ |
| list | Mostra codice sorgente con numeri riga |
| b `#` | Breakpoint al numero riga `#`|
| run | Avvio fino a breakpoint (se presente/i)* |
| display `i` | Mostra valore `i` ad ogni successiva iterazione del programma |
| print `i` | Mostra valore `i` una sola volta |
| n | Esegue riga successiva |
| quit | Esci da GDB |
| bt | Visualizza cronologie chiamate nel programma |

*con `run` è possibile ricavare riga di segmentation fault.

## Librerie
| Estensione | Tipologia | Contenuto |
| ------ | ------ | ------ |
| .h | File header | Contiene prototipi sottoprogrammi |
| .c | File .c | Contiene corpo sottoprogrammi dichiarati nel file header |

Nel programma :
```sh
#include ${libreria}.h
```
*Sostituire `${libreria}` con nome libreria*

- *Errore "ld" = errore linking del gcc (ricontrollare path)*

Per compilare, 
```sh
gcc ${libreria}.c ${nome_file}.c -o ${nome_exec}
```
*Sostituisci `${nome_file}` con il nome del file **.c** .*
*Sostituisci `${nome_exec}` con il nome dell'**eseguibile**.*
*Sostituisci `${libreria}` con il nome della **libreria**.*

Oppure:
- Compilazione senza linking, da **.c** a **.o**: ``` gcc -c ```
- Linking: ``` gcc file.o -o nome_exec ```

Se librerie/file sono in cartelle diverse, vanno sempre specificati i *path* relativi sia in gcc che nell'include.

La direttiva di preprocessore #ifndef (terminata dalla direttiva #endif) specifica che il codice compreso va mantenuto se il simbolo non esiste; altrimenti va cancellato. Quindi si usa:
```sh
#ifndef ${SIMBOLO}
#define ${SIMBOLO}
...
#endif
```
*Sostituisci `${SIMBOLO}` con simbolo univoco a tua scelta.*
