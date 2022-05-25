class Buffer:
    def __init__(self) -> None:
        self.frase = ""
    def setFrase(self, newFrase):
        self.frase = newFrase
    def getFrase(self):
        return self.frase
    def updateFrase(self, newFrase):
        self.frase = self.frase + newFrase
    def clearBuffer(self):
        fraseAux = self.frase
        self.frase = ""
        return fraseAux

class Cliente:
    def __init__(self, ip, porta) -> None:
        self.nome = ""
        self.mesa = -1
        self.socket = (ip,porta)
        self.pedidos = {}
        self.qntPedido = {}
        self.conta = 0.0
        self.desconto = 0.0
    def setNome(self, nome):
        self.nome = nome
    def setMesa(self, mesa):
        self.mesa = mesa
    def setConta(self, valor):
        self.conta = valor
    def getNome(self):
        return self.nome
    def getMesa(self):
        return self.mesa
    def getConta(self):
        return (self.conta - self.desconto)
    def getSocket(self):
        return self.socket
    def addPedido(self,pedido):
        prato = list(pedido.keys())[0]
        if prato in list(self.pedidos.keys()):
            self.qntPedido[prato] += 1;
        else:
            self.qntPedido.update({prato:1})
        self.pedidos.update(pedido)
        self.conta += list(pedido.values())[0]
    def addDesconto(self, desconto):
        self.desconto += desconto;
    def contaIndividual(self, buffer:Buffer):
        buffer.updateFrase("| {} |\n".format(self.nome))
        for prato,preco in self.pedidos.items():
            buffer.updateFrase("{} X {} => R${:.2f}\n".format(self.qntPedido[prato],prato,preco))
        buffer.updateFrase("Total - R${:.2f} - R${:.2f} (desconto) = {:.2f}\n".format(self.conta, self.desconto, (self.conta-self.desconto)))
        buffer.updateFrase("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n")

class Mesa:
    def __init__(self) -> None:
        self.clientes = []
    def getClientes(self):
        return self.clientes
    def adicionaCliente(self, cliente):
        self.clientes.append(cliente)
    def contaMesa(self, buffer:Buffer):
        conta = 0.0
        for cliente in self.clientes:
            cliente.contaIndividual(buffer)
            conta += cliente.getConta()
        buffer.updateFrase("Total da mesa: R${:.2f}\n".format(conta))
        buffer.updateFrase("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n")

def obtemCardapio():
    """Funcao que obtem o cardapio a partir do arquivo cardapio.txt"""
    cardapio = {}
    arq = open("cardapio.txt","r") 
    linhas = arq.readlines()
    for linha in linhas:
        if linha[0] != '-':
            numerodoprato = linha.split()[0]
            nomedoprato = []
            for palavra in linha.split()[2:-2]:
                nomedoprato.append(palavra)
            prato = ' '.join(nomedoprato)
            precodoprato = float(linha.split()[-1])
            cardapio[numerodoprato] = (prato,precodoprato)
        else:
            numerodasecao = linha.split()[1]
            nomedasecao = []
            for palavra in linha.split()[2:]:
                nomedasecao.append(palavra)
            secao = ' '.join(nomedasecao)
            cardapio[numerodasecao] = (numerodasecao,secao)
    arq.close()
    return cardapio


#inicializa a tabela de mesas
tabeladeMesas = {}

#armazena os clientes
clientes = {}

#obtem o cardapio
cardapio = obtemCardapio() 
  
#inicializa uma variavel que armazena os pratos
pratos = {} 

#preenche o dicionario de pratos a partir do cardapio
for chave, valor in cardapio.items():
    if chave != valor[0]:
        pratos.update({chave:valor})


def printCardapio(buffer:Buffer,cardapio):
    """Funcao que adiciona o cardapio no buffer de saida"""
    for chave,valor in cardapio.items():
        if chave == valor[0]:
            buffer.updateFrase("       {}\n".format(valor[1]))
        else:
            buffer.updateFrase("{} {} {:.2f}\n".format(chave, valor[0],valor[1]))

def fazerPedido(buffer:Buffer, clientAddress): 
    """Funcao que muda o estado do cliente para o estado 2
    (Cliente esta fazendo um pedido)"""
    buffer.updateFrase("Digite o codigo do prato:")

    clientes[clientAddress][0] = 2
    return

def confirmaPedido(buffer, clientAddress,  prato): #Estado 2
    """Funcao que confirma ou recusa o pedido e muda o estado do cliente"""
    mesa = clientes[clientAddress][2]
    posCliente = clientes[clientAddress][1]
    if prato not in pratos.keys():
        buffer.updateFrase("Codigo Inválido!")
        clientes[clientAddress][0] = 1
        return
    else:
        tabeladeMesas[mesa].getClientes()[posCliente].addPedido({pratos[prato][0]:pratos[prato][1]})
        buffer.updateFrase("Pedido Realizado!")
        clientes[clientAddress][0] = 1
        return

def printContaIndividual(buffer, clientAddress):
    """Funcao que insere a conta individual do cliente no buffer"""
    mesa = clientes[clientAddress][2]
    posCliente = clientes[clientAddress][1]
    tabeladeMesas[mesa].getClientes()[posCliente].contaIndividual(buffer)

def printContaMesa(buffer, mesa):
    """Funcao que insere a conta da mesa no buffer"""
    tabeladeMesas[mesa].contaMesa(buffer)

def printMenu(buffer:Buffer):
    """Funcao que insere o menu no buffer de saida"""
    buffer.updateFrase("Menu:\n1 - Cardápio\n2 - Pedir\n3 - Conta Individual\n4 - Conta da Mesa\n5 - Pagar\n6 - Sair")

def pagar(buffer:Buffer, clientAddress):
    """Funcao que obtem o valor da conta do cliente e muda seu estado para estado 3
    (cliente esta realizando pagamento)"""
    valorConta = tabeladeMesas[clientes[clientAddress][2]].getClientes()[clientes[clientAddress][1]].getConta()
    buffer.updateFrase("Sua conta foi de R${:.2f}. Digite o Valor a ser pago:".format(valorConta))

    clientes[clientAddress][0] = 3
    clientes[clientAddress][3] = valorConta
    return

def efetuaPagamento(buffer, clientAddress, valor):  #Estado 3
    """Funcao que verifica se o valor do cliente eh suficiente e 
    muda o estado do cliente para o correto"""
    valorConta = clientes[clientAddress][3]
    
    valor = float(valor)
    clientes[clientAddress][5] = valor

    if valor == valorConta:
        buffer.updateFrase("Valor confirmado, deseja confirmar a operação? [S/N]")
        clientes[clientAddress][0] = 31
        return
        
    elif valor > valorConta:
        buffer.updateFrase('''Você está pagando R${:.2f} a mais, esse valor vai ser descontado da conta da mesa,e o excedente sera tido como gorjeta.
                \nDeseja confirmar a operação? [S/N]'''.format(valor-valorConta))
        clientes[clientAddress][0] = 32
        return
        
    else:
        buffer.updateFrase("Valor Insuficiente, Pagamento Cancelado!")
        clientes[clientAddress][5] = 0.0
        printMenu(buffer)
        clientes[clientAddress][0] = 1
        return

def confirmaPagamento(buffer, clientAddress, confirmacao): #Estado 31
    """Funcao que confirma o pagamento do cliente (verifica se o
    cliente confirmou ou nao o pagamento)"""
    mesa = clientes[clientAddress][2]
    posCliente = clientes[clientAddress][1]
    valorConta = clientes[clientAddress][3]
    if confirmacao == "S" or confirmacao == "s":
        tabeladeMesas[mesa].getClientes()[posCliente].addDesconto(valorConta)
        buffer.updateFrase("Pagamento Efetuado, Obrigado!")
        clientes[clientAddress][0] = 1
        return
    elif confirmacao == "N" or confirmacao == "n":
        buffer.updateFrase("Okay, Pagamento cancelado!")
        clientes[clientAddress][5] = 0.0
        clientes[clientAddress][0] = 1
        return
    else:
        buffer.updateFrase("Não entendi! Pagamento Cancelado.")
        clientes[clientAddress][5] = 0.0
        clientes[clientAddress][0] = 1
        return

def confirmaDoacao(buffer, clientAddress, confirmacao): #Estado 32
    """Funcao que verifica se o cliente aceitou deixar o dinheiro excedente da conta para
    a mesa"""
    mesa = clientes[clientAddress][2]
    posCliente = clientes[clientAddress][1]
    valorConta = clientes[clientAddress][3]
    valor = clientes[clientAddress][5]
    if confirmacao == "S" or confirmacao == "s":
        if len(tabeladeMesas[mesa].getClientes()) == 1:
            buffer.updateFrase("Voce é o unico na sua mesa, deseja deixar o valor como gorjeta? [S/N]")
            clientes[clientAddress][0] = 321
            return
        else:

            tabeladeMesas[mesa].getClientes()[posCliente].addDesconto(valorConta)
            desconto = (valor-valorConta)/(len(tabeladeMesas[mesa].getClientes())-1)
            for cliente in tabeladeMesas[mesa].getClientes():
                if cliente.getNome() != tabeladeMesas[mesa].getClientes()[posCliente].getNome():
                    contaAtual = cliente.getConta()
                    if (contaAtual-desconto) > 0:
                        cliente.addDesconto(desconto)
                    else:
                        cliente.addDesconto(contaAtual)
            buffer.updateFrase("Pagamento Efetuado, Obrigado!")
            clientes[clientAddress][0] = 1
            return
    elif confirmacao == "N" or confirmacao == "n":
        buffer.updateFrase("Okay, Pagamento cancelado!")
        clientes[clientAddress][5] = 0.0
        clientes[clientAddress][0] = 1
        return 
    else:
        buffer.updateFrase("Não entendi! Pagamento Cancelado!")
        clientes[clientAddress][5] = 0.0
        clientes[clientAddress][0] = 1
        return 

def confirmarGorjeta(buffer, clientAddress, confirmacao): #Estado 321
    """Funcao que verifica se o cliente aceitou deixar o dinheiro excedente como gorjeta"""
    mesa = clientes[clientAddress][2]
    posCliente = clientes[clientAddress][1]
    valorConta = clientes[clientAddress][3]
    if confirmacao == "S" or confirmacao == "s":
        tabeladeMesas[mesa].getClientes()[posCliente].addDesconto(valorConta)
        buffer.updateFrase("Pagamento Efetuado, Obrigado!")
        clientes[clientAddress][0] = 1
        return
    else:
        buffer.updateFrase("Pagamento cancelado!")
        clientes[clientAddress][5] = 0.0
        clientes[clientAddress][0] = 1
        return

def adicionaCliente(buffer, clientAddress): #Estado 0  
    """Funcao que adiciona o cliente na tabela de mesas e inicializa o cliente no dicionarios dos
    clientes (estado, posicao na mesa...)"""
    mesa = clientes[clientAddress][2]
    nome = clientes[clientAddress][4]
    if mesa not in tabeladeMesas.keys():
        novaMesa = Mesa()
        tabeladeMesas.update({mesa:novaMesa})
    cliente = Cliente(clientAddress[0],clientAddress[1])
    cliente.setNome(nome)
    cliente.setMesa(mesa)
    tabeladeMesas[mesa].adicionaCliente(cliente)
    posCliente = tabeladeMesas[mesa].getClientes().index(cliente)

    printMenu(buffer)
    clientes[clientAddress][0] = 1
    clientes[clientAddress][1] = posCliente
        
    return  

def escolheMenu(buffer, clientAddress, op:str): #Estado 1
    """Funcao que a partir da operacao escolhida pelo cliente realiza
    as funcoes necessarias e seta o seu estado quando necessario"""
    mesa = clientes[clientAddress][2]
    posCliente = clientes[clientAddress][1]

    if op == '1' or op.lower() == 'cardápio':
        printCardapio(buffer, cardapio) 
        printMenu(buffer)
        return
    elif op == '2' or op.lower() == 'pedir':
        fazerPedido(buffer, clientAddress) #Estado 2
    elif op == '3' or op.lower() == 'conta individual':
        printContaIndividual(buffer, clientAddress) 
        printMenu(buffer)
        return
    elif op == '4' or op.lower() == 'conta da mesa':
        printContaMesa(buffer, mesa)
        printMenu(buffer)
        return
    elif op == '5' or op.lower() == 'pagar':
        pagar(buffer, clientAddress) #estado 3
    elif op == '6' or op.lower() == 'sair':
        if tabeladeMesas[mesa].getClientes()[posCliente].getConta() == 0.0:
            buffer.updateFrase("Volte sempre!")
            del(tabeladeMesas[mesa].getClientes()[posCliente])
            clientes.pop(clientAddress)

        else:
            buffer.updateFrase("Você ainda não efetuou o pagamento!")
            return
    else:
        buffer.updateFrase("Nao entendi!")
        return

def obtemMesa(buffer:Buffer, clientAddress): #Estado 9
    """Funcao que adiciona no buffer de saida o pedido para o cliente informar sua mesa"""
    buffer.updateFrase("Digite sua mesa:")
    clientes[clientAddress][0] = 0
    return

def cinToFome(buffer, resposta:str, clientAddress):
    """Funcao cinToFome, eh chamada sempre que uma mensagem eh recebida, verifica o cliente e 
    de acordo com o seu estado o encaminha para a funcionalidade correta.
    Se o cliente eh novo, adiciona ele no dicionario de clientes"""

    if (clientAddress not in clientes.keys()) and (resposta.lower() == "chefia"):
        clientes[clientAddress] = [9,-1,-1, 0.0, "", 0.0]
        buffer.updateFrase("Bem vindo(a) ao CinToFome!!\nDigite seu nome:")
        return
    elif (clientAddress not in clientes.keys()):
        buffer.updateFrase("Voce entrou em contato com o CinToFome. envie chefia se quiser entrar!")
        return
    elif clientes[clientAddress][0] == 9:
        clientes[clientAddress][4] = resposta
        obtemMesa(buffer, clientAddress)
        return
    elif clientes[clientAddress][0] == 0:
        clientes[clientAddress][2] = resposta
        adicionaCliente(buffer, clientAddress)
        return
    elif clientes[clientAddress][0] == 1:
        escolheMenu(buffer, clientAddress, resposta)
        return
    elif clientes[clientAddress][0] == 2:
        confirmaPedido(buffer, clientAddress, resposta)
        return
    elif clientes[clientAddress][0] == 3:
        efetuaPagamento(buffer, clientAddress, resposta)
        return
    elif clientes[clientAddress][0] == 31:
        confirmaPagamento(buffer, clientAddress, resposta)
        return
    elif clientes[clientAddress][0] == 32:
        confirmaDoacao(buffer, clientAddress, resposta)
        return
    elif clientes[clientAddress][0] == 321:
        confirmarGorjeta(buffer, clientAddress, resposta)
        return
