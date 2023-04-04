#pragma once
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
};


HRESULT InitWindow(_In_ HINSTANCE hInstance, _In_ INT nCmdShow);

//LRESULT CALLBACK WindowProc(_In_ HWND hWnd, _In_ UINT uMsg, _In_ WPARAM wParam, _In_ LPARAM lParam);

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
