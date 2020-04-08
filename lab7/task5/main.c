char password[8] = "secret";
int main(){
    char input[8];
    int temp;
    printf("please enter your password\n");
    scanf("%s", input);
    temp = 0;
    while( temp < 8 ){
        if(input[temp]>= 65 && input[temp] < 91){
            input[temp] = input[temp] + 32;
        }
        temp++;
    }
    if(strcmp(input, password)==0) {
        return 0;
    } 
    else{
        return -1;
    }
}
