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
    int Start = 1; // ����� ������ ���� ��
    int End = 30;  // ����� ������ �� ��

    // 1���� 30���� �ݺ�
    for (int i = Start; i <= End; ++i)
    {
        // ���ڸ� ���ڿ�(FString)�� ��ȯ
        FString Number = FString::FromInt(i);
        bool bIsClap = false; // "¦"�� ������� ���θ� ��Ÿ���� �÷���

        // ��ȯ�� ���ڿ��� �� ���ھ� �˻�
        for (TCHAR Char : Number) // TCHAR�� ����� �÷��� ������ ���� ó��
        {
            // ���� ���ڰ� '3', '6', '9' �� �ϳ����� Ȯ��
            if (Char == '3' || Char == '6' || Char == '9')
            {
                bIsClap = true; // "¦"�� ����ؾ� ��
                break; // �ϳ��� '3', '6', '9'�� �߰��ϸ� �˻� ����
            }
        }

        if (bIsClap)
        {
            // "¦"�� ��� (���ڿ� 3, 6, 9 �� �ϳ��� ���Ե� ���)
            UE_LOG(LogTemp, Warning, TEXT("¦"));
        }
        else
        {
            // ���ڸ� ��� (���ڿ� 3, 6, 9�� ���� ���)
            UE_LOG(LogTemp, Warning, TEXT("%d"), i);
        }
    }
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

