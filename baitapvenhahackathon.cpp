#include<stdio.h>

int main(){
	int arr[50];
	int choice, number;
	do{
	int max=0, Max=0; 
	int position, value;
	int total, check=-1, temp, minus; 
	int maxxin, maxTwo, min, minTwo; 
		printf("\n\t           ---MENU---\n");
		printf("1. Nhap so luong va gia tri cho cac phan tu\n");
		printf("2. In mang (arr[0]=..., arr[1]=...)\n");
		printf("3. Dem so luong so hoan hao\n");
		printf("4. Dem so luong so nguyen to\n");
		printf("5. Tim gia tri lon thu 2\n");
		printf("6. Tim gia tri nho thu 2\n");
		printf("7. Them phan tu tai vi tri\n");
		printf("8. Xao phan tu tai vi tri\n");
		printf("9. Sap xep mang tang dan (Sap xep chen)\n");
		printf("10. Sap xep mang giam dan (Sap xep chen)\n");
		printf("11. Tim kiem phan tu (Tim kiem nhi phan)\n");
		printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
		printf("13. Sap xep va hien thi so chan dung truoc so le dung sau\n");
		printf("14. Dao nguoc mang\n");
		printf("15. Thoat\n");
		printf("\nLua chon cua ban:"); 
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\nMoi ban nhap phan tu: ");
				scanf("%d", &number); 
				if(number<=0 || number>100){
					printf("So phan tu khong hop le.\n"); 
				} else {
					printf("Moi ban nhap gia tri cac phan tu.\n"); 
				} 
				for(int i=0;i<number;i++){
					printf("Phan tu arr[%d]= ", i+1);
					scanf("%d", &arr[i]); 
				} 
				printf("\n");
			break;
			case 2:
				printf("Gia tri cac phan tu dang quan ly: ");
			    for(int i=0;i<number;i++){
			    	printf("  arr[%d]=%d  ", i+1 , arr[i]); 
				}
				printf("\n"); 
			break;
			case 3:
				if (number == 0) {
                     printf("Mang dang rong\n");
                } else {
                    int count = 0;
                    for (int i = 0; i < number; i++) {
                         int minus = 0;
                        for (int j = 1; j <= arr[i] / 2; j++) {
                            if (arr[i] % j == 0) {
                                minus += j;
                            }
                        }
                        if (minus == arr[i]) {
                            count++;
                        }
                    }
                    printf("So luong so hoan hao trong mang: %d\n", count);
                }
			break;
			case 4:
				printf("Cac so nguyen to trong mang la: ");
                for (int i = 0; i <= number; i++) {
	                int isPrime = 1;
	                if (arr[i] <= 1) { 
	                    isPrime = 0;
	                } else {
	                    for (int j = 2; j * j <= arr[i]; j++) {
	                        if (arr[i] % j == 0) {
	                            isPrime = 0; 
	                            break;
	                        }
	                    }
	                }
	                if (isPrime) {
	                    printf("%d ", arr[i]);
	                }
                }
                printf("\n");
			break;
			case 5:
				if (number < 2) {
                   printf("Khong hop le\n");
                } else {
                    int min = arr[0], min_2 = arr[1];
                    if (arr[0] < arr[1]) {
                        min = arr[1];
                        min_2 = arr[0];
                    }
                    for (int i = 2; i < number; i++) {
                        if (arr[i] > min) {
                            min_2 = min;
                            min = arr[i];
                        } else if (arr[i] < min_2 && arr[i] != min) {
                                 min_2 = arr[i];
                        }
                    } 
                        printf("Gia tri lon thu trong mang la: %d\n", min_2);
                }
			break;
			case 6:
			   if (number < 2) {
                   printf("Khong hop le\n");
                } else {
                    int min = arr[0], min_2 = arr[1];
                    if (arr[0] > arr[1]) {
                        min = arr[1];
                        min_2 = arr[0];
                    }
                    for (int i = 2; i < number; i++) {
                        if (arr[i] < min) {
                            min_2 = min;
                            min = arr[i];
                        } else if (arr[i] < min_2 && arr[i] != min) {
                                 min_2 = arr[i];
                        }
                    } 
                        printf("Gia tri nho thu 2 trong mang la: %d\n", min_2);
                }
			break; 
			case 7:
				printf("Mang truoc khi them: "); 
			    for(int i=0;i<number;i++){
			    	printf("%d ", arr[i]); 
				} 
				printf("\nNhap vi tri muon them moi phan tu: ");
				scanf("%d",&position);
				printf("Nhap gia tri muon them moi vao mang: ");
				scanf("%d",&value);
				if(position<0 || position > number){
					printf("Vi tri ban nhap khong hop le\n");
					continue; 
				}else {
					for (int i = number; i > position; i--) {
	       				arr[i] = arr[i - 1];
	    			}
	    			arr[position]=value;
	    			number++;
				}
				printf("Mnag sau khi them: "); 
				for(int i =0; i<number;i++){
					printf("%d  ", arr[i]);
				}
				printf("\n");
			break;
			case 8:
				printf("Mang truoc khi xoa: "); 
			    for(int i=0;i<number;i++){
			    	printf("%d ", arr[i]); 
				}
			    printf("\nNhap vao vi tri ban muon xoa: ");
				scanf("%d", &position);
				if(position <0 || position>number){
					printf("So ban nhap khong hop le!");
				}
				for(int i =position; i<number-1;i++){
					arr[i]=arr[i+1];
				}
	            number--;
				printf("Mang sau khi xoa: "); 
				for(int i =0; i<number;i++){
					printf("%d  ", arr[i]);
				}
				printf("\n");
			break;
			case 9:	
			    for(int i=0; i<number;i++){
				int key = arr[i];
				int j;
				for(j=i-1; j>=0 && arr[j]>key; j--){
					arr[j+1]= arr[j];
				}
				arr[j+1]=key;
				}
				printf("Cac phan tu trong mang sau khi sap xep la: \n");
				for(int i=0; i<number;i++){
					printf("  %d  ", arr[i]);
				}
				printf("\n");
			break;
			case 10:
			    for(int i=0;i<number-1;i++) {
					for(int j=0;j<number-i-1;j++) {
						if(arr[j]<arr[j+1]) {
							temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
	        	} 
				for(int i=0;i<number;i++) {
					printf("%d ",arr[i]);	
				}
			break; 
			case 11:
				printf("Ban muon tim kiem phan tu nao trong mang: ");
				scanf("%d",&total);
				for(int i=0;i<number;i++){
					if(total == arr[i]){
						check++;
						minus = i;
						break;
					}
				}
				if(check!=-1){
					printf("Phan tu ban dang tim kiem (%d) nam o vi tri:%d trong mang",total,minus);
				}else{
					printf("Phan tu khong ton tai trong mang");
				}
				printf("\n");
				break;
			case 12: 
			    if (number==0){
			        printf("Khong nhap mang a!\n");
			        break;
			    }
			    for (int i=0;i<number;i++){
			        for (int j = i + 1;j<number;){
			            if (arr[i] == arr[j]) {
			                for (int k = j;k<number - 1;k++){
			                    arr[k] = arr[k + 1];
			                }
			                number--; 
			            }else{
			                j++; 
			            }
			        }
			    }
			    printf("Cac phan tu duy nhat trong mang la:\n");
			    for (int i=0;i<number;i++) {
			        printf("%d ", arr[i]);
			    }
			    printf("\n");
			    break; 				 
			case 13:
				printf("Cac so sep chan truoc va le sau la: ");
				for(int i = 1;i<number;i++){
					if(i % 2 == 0){
						printf("%d", i);
					}
				}
				for(int i=0;i<number;i++){
					if(i % 2 != 0){
						printf("%d", i); 
					} 
				} 
				break;
			case 14:
				printf("Gia tri cac phan tu duoc dao nguoc: \n");
			    for(int i=number;i>=0;i--){
			    	printf("%d", arr[i]); 
				}
				printf("\n");
				break;
			case 15:
				printf("Thoat chuong trinh.\n");
				return 0;
				break;
		default:
		    printf("Phan tu khong hop le\n");
			printf("Sai phan tu la mat em!!");		
		}
	}while(choice!=15);
	return 0;
}




