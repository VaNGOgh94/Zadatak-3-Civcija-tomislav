struct redStrukt {
  kliStrukt klijent;
  union {redStrukt *front, *sl;};
  redStrukt *rear;
};

kliStrukt FrontQ(redStrukt *red){
  return red->front->sl->klijent;   
}

short EnQueueQ(kliStrukt unos, redStrukt *red){
  red->rear=red->rear->sl=new redStrukt;
  red->rear->klijent=unos;
  red->rear->sl=NULL;
  return 1;
}

void DeQueueQ(redStrukt *red){
  if(red->rear!=red->front){
    redStrukt *glava=red->front;
    red->front=glava->sl;
    delete glava;
  }
}

bool IsEmptyQ(redStrukt *red){
  if(red->front==red->rear)
    return true;
  return false;
}

redStrukt *InitQ(redStrukt *red){
  red=new redStrukt;
  red->front=new redStrukt;
  red->rear=red->front;
  return red;
}
