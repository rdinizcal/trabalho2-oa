
# Trabalho 2 - Organização de Arquivos UnB 2/2016

One Paragraph of project description goes here

## To-Do

* Itens 1 e 2 do menu principal
* Nao aceitar chaves duplicadas
* Comportamento estranho ao mostrar chaves (em relacao aos filhos)
	* O problema pode ser devido a insercao incorreta das chaves
	* Ou devido a implementacao incorreta do metodo ArvoreB::print()
* Testar validade da ArvoreB criada no SetUp (Arquivos Teste data1.txt data2.txt)

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

