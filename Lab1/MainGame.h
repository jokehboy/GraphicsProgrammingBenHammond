#pragma once
#include <SDL\SDL.h>
#include <GL/glew.h>
#include "Display.h" 
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "transform.h"
#include "Audio.h"

enum class GameState{PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();

private:

	void initSystems();
	void processInput();
	void gameLoop();
	void drawGame();


	void linkToonShader();
	void linkRimShader();
	void linkGeoShader();
	void linkSkyboxShader();
	void linkReflectionShader();
	void linkMyShader();



	void SkyBox();
	GLuint skyboxVAO, skyboxVBO, cubemapTexture;
	vector<std::string> faces;
	Texture skybox;
	Shader shaderSkybox;
	void initSkybox();

	bool collision(glm::vec3 m1Pos, float m1Rad, glm::vec3 m2Pos, float m2Rad);
	//void playAudio(unsigned int Source, glm::vec3 pos);

	Display _gameDisplay;
	GameState _gameState;
	Mesh mesh1;
	Mesh mesh2;
	Mesh mesh3;

	Camera myCamera;

	Shader toonShader;
	Shader rimShader;
	Shader geoShader;
	Shader reflectionShader;
	Shader myShader;


	//Audio audioDevice;

	float counter;
	unsigned int whistle;
	unsigned int backGroundMusic;
};

