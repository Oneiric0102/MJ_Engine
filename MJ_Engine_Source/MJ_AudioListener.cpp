#include "MJ_AudioListener.h"
#include "MJ_Transform.h"
#include "MJ_GameObject.h"
#include "MJ_Fmod.h"

namespace MJ
{
	AudioListener::AudioListener() 
		:Component(eComponentType::AudioListener)
	{

	}
	AudioListener::~AudioListener(){}

	void AudioListener::Initialize(){}
	void AudioListener::Update(){}

	void AudioListener::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Fmod::Set3DListenerAttributes(&pos);
	}

	void AudioListener::Render(HDC hdc){}
}