int insieme_valori(nodo_t *l1, nodo_t *l2){
	nodo_t *tmp1, *tmp2;
	int min1, max1, min2, max2;
	if(l1 && l2){
		for(tmp1=l1, min1 = max1 = tmp1->num; tmp1 = tmp1->next){
			if(min1 > tmp1->num)
				min1 = tmp1->num;
			if(max1 < tmp1->num)
				max1 = tmp1->num;
		}
		for(tmp2=l2, min2 = max2 = tmp2->num; tmp2 = tmp2->next){
			if(min2 > tmp2->num)
				min2 = tmp2->num;
			if(max2 < tmp2->num)
				max2 = tmp2->num;
		}
		return min1 == min2 && max1 == max2;
	}else{
		printf("Liste vuote\n");
		return 0;
	}
}