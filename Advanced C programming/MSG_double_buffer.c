
buf_write{
  while(1){
    wait(empty[swapW]);

    write(buf[swapW]);

    signal(full[swapW]);
    swapW = (swapW +1)%2;

  }
}

buf_read{
  while(1){
    wait(meC);
    wait(full[swapR]);

    read(buf[swapR]);

    signal(empty[swapR]);
    swapR = (swapR + 1)%2;
    signal(meC);
  }
}
