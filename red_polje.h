struct redStrukt {
  kliStrukt polje [10000];
  short front, rear;
};

kliStrukt FrontQ(redStrukt *red){
  return red->polje[red->front];
}

short AddOne(int kursor){
  return (kursor+1)%(sizeof(redStrukt)/sizeof(kliStrukt)-2); 
}

short EnQueueQ(kliStrukt unos, redStrukt *red){
  if(AddOne(AddOne(red->rear))==(red->front))
    return -1;
  red->polje[red->rear=AddOne(red->rear)]=unos;
  return 1;
}

bool IsEmptyQ(redStrukt *red){
  if(red->front==AddOne(red->rear))
    return true;
  return false;
}

void DeQueueQ(redStrukt *red){
  if(red->front!=AddOne(red->rear))
    red->front=AddOne(red->front);  
}

redStrukt *InitQ(redStrukt *red){
  red=new redStrukt;
  red->front=0;
  red->rear=sizeof(redStrukt)/sizeof(kliStrukt)-3;
  return red;
}
