#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int diai,mesi,anoi,diaf,mesf,anof,dias,m;

    scanf("%d/%d/%d %d/%d/%d",&diai,&mesi,&anoi,&diaf,&mesf,&anof);


    if(anof != anoi){
        if(mesi == 1||mesi == 3||mesi == 5||mesi == 7||mesi == 8||mesi == 10||mesi == 12){m = 31;
        }else if(mesi == 4||mesi == 6||mesi == 9||mesi == 11){m = 30;
        }else if(mesi == 2&&anoi%4==0&&anoi%100==0&&anoi%400==0){m = 29;
        }else if(mesi == 2&&anoi%4==0&&anoi%100==0&&anoi%400!=0){m=28;
        }else if(mesi == 2&&anoi%4==0&&anoi%100!=0){m = 29;
        }else if(mesi == 2&&anoi%4!=0){m = 28;};

        dias = m - diai;

        for(int i = mesi+1; i <= 12 ; i++){

            if(i == 1||i == 3||i == 5||i == 7||i == 8||i == 10||i == 12){dias  += 31;
            }else if(i == 4||i == 6||i == 9||i == 11){dias += 30;
            }else if(i == 2&&anoi%4==0&&anoi%100==0&&anoi%400==0){dias += 29;
            }else if(i == 2&&anoi%4==0&&anoi%100==0&&anoi%400!=0){dias += 28;
            }else if(i == 2&&anoi%4==0&&anoi%100!=0){dias += 29;
            }else if(i == 2&&anoi%4!=0){dias += 28;};

        };

        for(int i = anoi+1; i < anof; i++){

            if(i%4!=0){dias += 365;
            }else if(i%100==0&&i%400==0){dias += 366;
            }else if(i%100==0&&i%400!=0){dias += 365;
            }else if(i%100!=0){dias += 366;};

        };

        for(int i = 1; i < mesf ; i++){

            if(i == 1||i == 3||i == 5||i == 7||i == 8||i == 10||i == 12){dias  += 31;
            }else if(i == 4||i == 6||i == 9||i == 11){dias += 30;
            }else if(i == 2&&anof%4==0&&anof%100==0&&anof%400==0){dias += 29;
            }else if(i == 2&&anof%4==0&&anof%100==0&&anof%400!=0){dias += 28;
            }else if(i == 2&&anof%4==0&&anof%100!=0){dias += 29;
            }else if(i == 2&&anof%4!=0){dias += 28;};

        };

        dias += diaf;

    }else if(mesf != mesi){

        if(mesi == 1||mesi == 3||mesi == 5||mesi == 7||mesi == 8||mesi == 10||mesi == 12){m = 31;
        }else if(mesi == 4||mesi == 6||mesi == 9||mesi == 11){m = 30;
        }else if(mesi == 2&&anoi%4==0&&anoi%100==0&&anoi%400==0){m = 29;
        }else if(mesi == 2&&anoi%4==0&&anoi%100==0&&anoi%400!=0){m=28;
        }else if(mesi == 2&&anoi%4==0&&anoi%100!=0){m = 29;
        }else if(mesi == 2&&anoi%4!=0){m = 28;};

        dias = m - diai;

        for(int i = mesi+1; i < mesf ; i++){

            if(i == 1||i == 3||i == 5||i == 7||i == 8||i == 10||i == 12){dias  += 31;
            }else if(i == 4||i == 6||i == 9||i == 11){dias += 30;
            }else if(i == 2&&anoi%4==0&&anoi%100==0&&anoi%400==0){dias += 29;
            }else if(i == 2&&anoi%4==0&&anoi%100==0&&anoi%400!=0){dias += 28;
            }else if(i == 2&&anoi%4==0&&anoi%100!=0){dias += 29;
            }else if(i == 2&&anoi%4!=0){dias += 28;};

        };

        dias += diaf;


    }else{dias = diaf - diai;};

    printf("%d",dias);

	return 0;
}