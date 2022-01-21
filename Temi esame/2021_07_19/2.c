int somma_successivi(nodo_t *h){
	nodo_t *tmp;
	int sum;
	sum = 0;
	if(h){
		for(tmp = h; tmp; tmp = tmp->next)
			sum += tmp->num;
		free(tmp);
	}
	return sum;
}

nodo_t* nuovalista(nodo_t *h){
	npdp_t *tmp, *new;
	tmp = new = NULL;
	
	for(tmp = h; tmp; tmp = tmp->next)
		if(tmp->num > somma_successivi(tmp->next))
			new = inserisciInCoda(new, tmp->num);
	return new;
}