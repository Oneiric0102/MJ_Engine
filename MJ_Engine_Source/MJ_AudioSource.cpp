#include "MJ_AudioSource.h"
#include "MJ_Transform.h"
#include "MJ_GameObject.h"
#include "MJ_Fmod.h"

namespace MJ
{
	AudioSource::AudioSource() 
		:Component(eComponentType::AudioSource)
	{}
	AudioSource::~AudioSource() {}

	void AudioSource::Initialize() {}
	void AudioSource::Update() {}
	void AudioSource::LateUpdate() 
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		mAudioClip->Set3DAttributes(pos);
	}
	void AudioSource::Render(HDC hdc) {}

	void AudioSource::Play() 
	{
		mAudioClip->Play();
	}
	void AudioSource::Stop() 
	{
		mAudioClip->Stop();
	}
	void AudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}