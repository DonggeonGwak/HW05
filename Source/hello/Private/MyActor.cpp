// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    int Start = 1; // 출력할 숫자의 시작 값
    int End = 30;  // 출력할 숫자의 끝 값

    // 1부터 30까지 반복
    for (int i = Start; i <= End; ++i)
    {
        // 숫자를 문자열(FString)로 변환
        FString Number = FString::FromInt(i);
        bool bIsClap = false; // "짝"을 출력할지 여부를 나타내는 플래그

        // 변환된 문자열을 한 글자씩 검사
        for (TCHAR Char : Number) // TCHAR를 사용해 플랫폼 독립적 문자 처리
        {
            // 현재 글자가 '3', '6', '9' 중 하나인지 확인
            if (Char == '3' || Char == '6' || Char == '9')
            {
                bIsClap = true; // "짝"을 출력해야 함
                break; // 하나라도 '3', '6', '9'를 발견하면 검사 종료
            }
        }

        if (bIsClap)
        {
            // "짝"을 출력 (숫자에 3, 6, 9 중 하나가 포함된 경우)
            UE_LOG(LogTemp, Warning, TEXT("짝"));
        }
        else
        {
            // 숫자를 출력 (숫자에 3, 6, 9가 없는 경우)
            UE_LOG(LogTemp, Warning, TEXT("%d"), i);
        }
    }
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

