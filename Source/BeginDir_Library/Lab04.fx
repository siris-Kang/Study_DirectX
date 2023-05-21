// Create Constant Buffer
cbuffer cbView : register(b0)
{
	matrix View;
};
cbuffer cbProjection : register(b1)
{
	matrix Projection;
};
cbuffer cbWorld : register(b2)
{
	matrix World;
};

// Texture
Texture2D txDiffuse : register(t0);
SamplerState samLinear : register(s0);


struct VS_INPUT
{
	float4 Position : POSITION;
	float2 TexCoord : TEXCOORD0;
};
struct PS_INPUT
{
	float4 Position : SV_POSITION;
	float2 TexCoord : TEXCOORD0;
};


// Vertex Shader
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;
	output.Position = mul(input.Position, World);
	output.Position = mul(output.Position, View);
	output.Position = mul(output.Position, Projection);
	output.TexCoord = input.TexCoord;

	return output;
}

// Pixel Shader
float4 PS(PS_INPUT input) : SV_Target
{
	return txDiffuse.Sample(samLinear, input.TexCoord);
}
