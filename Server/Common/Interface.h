
__interface IUpdate
{
	ErrorResult Update(DeltaTime delta_time);
};

__interface IInitalize
{
	ErrorResult Initalize();
};

__interface IRelease
{
	ErrorResult Release();
};