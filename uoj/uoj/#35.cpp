#include <stdio.h>
#include <iostream>
#include <string.h>

bool isNumber(char c){
    if(c == '+' ||c == '-' ||c == '*' ||c == '/' ||c == '(' ||c == ')'||c == '=' ){
        return false;
    }
    return true;
}

typedef enum TYPE{
    number,symbol
} TYPE;

typedef struct state{
    TYPE nowstate;
    int poiner;
    char str[1000];
    int count;
} State;

static State state;
typedef struct NODE{
    TYPE type;
    char str[1000];
} NODE;

void initstate(State *state){
    state->nowstate = symbol;//init state
    state->poiner = 0;
    state->count = 0;
}
NODE *createNode(TYPE type){
    NODE* node =  new NODE;
    node->type = type;
    state.str[state.poiner] = '\0';
    strcpy(node->str, state.str);
    state.poiner = 0;
    return node;
}

NODE *token[1000];

void gettaken(char letter){
    if(isNumber(letter)){//is number
        state.nowstate = number;
        state.str[state.poiner] = letter;
        state.poiner+=1;
    }else{//is symbol
        if(state.nowstate == number){//number node
            token[state.count] = createNode(number);
            state.count+=1;
        }
        state.nowstate = symbol;
        state.str[state.poiner] = letter;
        state.poiner+=1;
        token[state.count] = createNode(symbol);
        state.count +=1;
    }
}



//grammar analyse
int lookahead(0);
void getToken(){
    lookahead +=1;
}
int stack[1000];
void E();
void F(){
    if(token[lookahead]->str[0] == '('){
        printf("%s\n",token[lookahead]->str);
        getToken();
        E();
        if(token[lookahead]->str[0] == ')'){
            printf("%s\n",token[lookahead]->str);
            getToken();
        }else{
            
        }
    }else if(token[lookahead]->type == number){
            printf("%s\n",token[lookahead]->str);
            getToken();
    }else{
        printf("error");
    }
    
}

void T1(){
    if(token[lookahead]->str[0] == '*' || token[lookahead]->str[0] == '/'){
        printf("%s\n",token[lookahead]->str);
        getToken();
        F();
        T1();
    }else{
        
    }
}

void T(){
        F();
        T1();
}

void E1(){
    if(token[lookahead]->str[0] == '+' || token[lookahead]->str[0] == '-' ){
        printf("%s\n",token[lookahead]->str);
        getToken();
        T();
        E1();
    }else{
        
    }
}

void E(){
    T();
    E1();
}

int main(){
    initstate(&state);
    while (1) {
        char letter;
        scanf("%c",&letter);
        if(letter == '\n'){break;}
        gettaken(letter);
    }
    NODE* nodeter = new NODE;
    nodeter->type = symbol;
    nodeter->str[0] = '#';
    nodeter->str[1] = '\0';
    token[state.count-1] = nodeter;//= 变为 #
    //test token
//    for(int i = 0;i<state.count;i++){
//        printf("str:%s\n",token[i]->str);
//    }
    E();
    printf("%s",token[lookahead]->str);
    
    return 0;
}
