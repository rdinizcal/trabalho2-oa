
# Trabalho 2 - Organização de Arquivos UnB 2/2016

## To-Do

* Buscar: done.
* Inserir: 
	* Falta inserir registro nos txts
* Mostrar: done.

## Plug'n'play

Para compilar o projeto vá até a pasta /build e execute o comando:
```
make
```
Então, será criado um arquivo .main na pasta principal.
Para rodá-lo basta executar:
```
./main nome_do_arquivo.txt -r 1|2
```
1 para arquivo com registros de tamanho variável; 
2 para arquivo com registros de tamanho fixo.
Exemplos:
```
./main data1.txt -r 1
```
```
./main data2.txt -r 2
```

