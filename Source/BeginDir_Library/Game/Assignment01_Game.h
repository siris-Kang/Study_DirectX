﻿#pragma once
/*+===================================================================
  File:      GAME.H
  Summary:   Game header file that contains declarations of functinos
             used for the lab samples of Game Graphics Programming
             course.
  Functions: PrintHi
  © 2022 Kyung Hee University
===================================================================+*/
#pragma once

#include "Common.h"

struct SimpleVertex
{
    XMFLOAT3 Pos;
    XMFLOAT4 Color;
};

struct ConstantBuffer {
    XMMATRIX World;
    XMMATRIX View;
    XMMATRIX Projection;
};


HRESULT InitWindow(_In_ HINSTANCE hInstance, _In_ INT nCmdShow);



HRESULT InitDevice();
void CleanupDevice();
void Render();


HRESULT CompileShaderFromFile
(
    _In_ PCWSTR pszFileName, // FileName
    _In_ PCSTR pszEntryPoint, // EntryPoint
    _In_ PCSTR pszShaderModel, // Shader target
    _Outptr_ ID3DBlob** ppBlobOut // ID3DBlob out
);

void HandleInput(FLOAT deltaTime);
void Update(FLOAT deltaTime); 


struct InputDirections
{
    BOOL bFront;
    BOOL bBack;
    BOOL bLeft;
    BOOL bRight;
    BOOL bUp;
    BOOL bDown;
};
struct MouseRelativeMovement
{
    LONG X;
    LONG Y;
};