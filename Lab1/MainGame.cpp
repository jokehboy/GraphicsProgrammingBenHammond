#include "MainGame.h"
#include "Camera.h"
#include <iostream>
#include <string>

Transform transform;

MainGame::MainGame()
{
	
	_gameState = GameState::PLAY;
	Display* _gameDisplay = new Display(); //new display
    Mesh* mesh1();
	Mesh* mesh2();
	Mesh* mesh3();
	Shader* toonShader();
	Shader* rimShader();
	Shader* geoShader();
	Shader* shaderSkybox();
	Shader* reflectionShader();
	Shader* rainEffect();
	Shader* myShader();
	//Audio* audioDevice();
}

MainGame::~MainGame()
{
}

void MainGame::run()
{
	initSystems(); 
	gameLoop();
}

void MainGame::initSystems()
{
	_gameDisplay.initDisplay(); 
	//whistle = audioDevice.loadSound("..\\res\\bang.wav");
	//backGroundMusic = audioDevice.loadSound("..\\res\\background.wav");
	
	
	

	mesh1.loadModel("..\\res\\monkey3.obj");
	mesh2.loadModel("..\\res\\Skull.obj");
	mesh3.loadModel("..\\res\\Bird_v1_L2.123ca5dbb1bc-8ef6-44e4-b558-3e6e2bbc7dd7\\12248_Bird_v1_L2.obj");


	myShader.init("..\\res\\Toon.vert", "..\\res\\Toon.frag"); //new shader
	//rimShader.init("..\\res\\Rim.vert", "..\\res\\Rim.frag");
	shaderSkybox.init("..\\res\\shaderSkybox.vert", "..\\res\\shaderSkybox.frag");
	geoShader.initGeometry("..\\res\\shaderGeoText.vert", "..\\res\\shaderGeoText.geom", "..\\res\\shaderGeoText.frag");
	reflectionShader.init("..\\res\\shaderReflection.vert", "..\\res\\shaderReflection.frag");
	

	
	
	myCamera.initCamera(glm::vec3(0, 0, -5), 70.0f, (float)_gameDisplay.getWidth()/_gameDisplay.getHeight(), 0.01f, 1000.0f);

	counter = 1.0f;

	initSkybox();
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
		collision(mesh1.getSpherePos(), mesh1.getSphereRadius(), mesh2.getSpherePos(), mesh2.getSphereRadius());
		//playAudio(backGroundMusic, glm::vec3(0.0f,0.0f,0.0f));
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;

	while(SDL_PollEvent(&evnt)) //get and process events
	{
		switch (evnt.type)
		{
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;
		}
	}
	
}


bool MainGame::collision(glm::vec3 m1Pos, float m1Rad, glm::vec3 m2Pos, float m2Rad)
{
	float distance = glm::sqrt((m2Pos.x - m1Pos.x)*(m2Pos.x - m1Pos.x) + (m2Pos.y - m1Pos.y)*(m2Pos.y - m1Pos.y) + (m2Pos.z - m1Pos.z)*(m2Pos.z - m1Pos.z));

	if (distance < (m1Rad + m2Rad))
	{
		//audioDevice.setlistener(myCamera.getPos(), m1Pos); //add bool to mesh
		//playAudio(whistle, m1Pos);
		return true;
	}
	else
	{
		return false;
	}
}

//void MainGame::playAudio(unsigned int Source, glm::vec3 pos)
//{
//	
//	ALint state; 
//	alGetSourcei(Source, AL_SOURCE_STATE, &state);
//	/*
//	Possible values of state
//	AL_INITIAL
//	AL_STOPPED
//	AL_PLAYING
//	AL_PAUSED
//	*/
//	if (AL_PLAYING != state)
//	{
//		audioDevice.playSound(Source, pos);
//	}
//}


void MainGame::initSkybox()
{
	vector<std::string> faces
	{
		"..\\res\\skybox\\posx.jpg" ,
		"..\\res\\skybox\\negx.jpg",
		"..\\res\\skybox\\posy.jpg",
		"..\\res\\skybox\\negy.jpg",
		"..\\res\\skybox\\posz.jpg",
		"..\\res\\skybox\\negz.jpg"
		
	};
	cubemapTexture = skybox.loadCubeMap(faces);

	float skyboxVertices[] =
	{
		-6.0f,  6.0f, -6.0f,
		-6.0f, -6.0f, -6.0f,
		6.0f, -6.0f, -6.0f,
		6.0f, -6.0f, -6.0f,
		6.0f,  6.0f, -6.0f,
		-6.0f,  6.0f, -6.0f,

		-6.0f, -6.0f,  6.0f,
		-6.0f, -6.0f, -6.0f,
		-6.0f,  6.0f, -6.0f,
		-6.0f,  6.0f, -6.0f,
		-6.0f,  6.0f,  6.0f,
		-6.0f, -6.0f,  6.0f,

		6.0f, -6.0f, -6.0f,
		6.0f, -6.0f,  6.0f,
		6.0f,  6.0f,  6.0f,
		6.0f,  6.0f,  6.0f,
		6.0f,  6.0f, -6.0f,
		6.0f, -6.0f, -6.0f,

		-6.0f, -6.0f,  6.0f,
		-6.0f,  6.0f,  6.0f,
		6.0f,  6.0f,  6.0f,
		6.0f,  6.0f,  6.0f,
		6.0f, -6.0f,  6.0f,
		-6.0f, -6.0f,  6.0f,

		-6.0f,  6.0f, -6.0f,
		6.0f,  6.0f, -6.0f,
		6.0f,  6.0f,  6.0f,
		6.0f,  6.0f,  6.0f,
		-6.0f,  6.0f,  6.0f,
		-6.0f,  6.0f, -6.0f,

		-6.0f, -6.0f, -6.0f,
		-6.0f, -6.0f,  6.0f,
		6.0f, -6.0f, -6.0f,
		6.0f, -6.0f, -6.0f,
		-6.0f, -6.0f,  6.0f,
		6.0f, -6.0f,  6.0f
	};

	//use opengl to generate and bind data to buffers
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

}


void MainGame::SkyBox()
{
	glDepthFunc(GL_LEQUAL);//change depth test func. so depth test passes when values are = depth buffer's content
	shaderSkybox.Bind();
	shaderSkybox.setInt("skybox", 0);

	//view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix

	shaderSkybox.setMat4("view", myCamera.getView());
	shaderSkybox.setMat4("projection", myCamera.getProjection());
	//skyboxCube

	glBindVertexArray(skyboxVAO);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
	glDepthFunc(GL_LESS);//set depth func. back to default val.

}


void MainGame::linkGeoShader()
{
	geoShader.setMat4("transform", transform.GetModel());
	//geoShader.setMat4("u_pm", myCamera.getProjection());
	//geoShader.setMat4("u_vm", myCamera.getView());



}
void MainGame::linkReflectionShader()
{
	reflectionShader.setMat4("view", myCamera.getView());
	reflectionShader.setMat4("projection", myCamera.getProjection());
	reflectionShader.setMat4("model", transform.GetModel());
	reflectionShader.setVec3("cameraPos", myCamera.getPos());
	shaderSkybox.setInt("skybox", 0);

}

void MainGame::linkRimShader()
{
	rimShader.setMat4("transform", transform.GetModel());
	//rimShader.setMat4("u_pm", myCamera.getProjection());
	rimShader.setMat4("u_vm", myCamera.getView());

}

void MainGame::linkMyShader()
{
	myShader.setMat4("view", myCamera.getView());
	myShader.setMat4("projection", myCamera.getProjection());
	myShader.setMat4("model", transform.GetModel());
	myShader.setVec3("modelColor", glm::vec3(1, 0.84, 0));



	
}

void MainGame::drawGame()
{
	_gameDisplay.clearDisplay(0.0f, 0.0f, 0.0f, 1.0f);
	//linkToonShader();
	//linkRimShader();
	
	

	SkyBox();

	Texture texture("..\\res\\bricks.jpg"); //load texture
	Texture texture1("..\\res\\water.jpg"); //load texture
	
	
	

	transform.SetPos(glm::vec3(sinf(counter), 1.5, 0.0));
	transform.SetRot(glm::vec3(0.0, counter*2, counter * 1));
	transform.SetScale(glm::vec3(0.6, 0.6, 0.6));

	//toonShader.Bind();		//rimShader.Bind();			//geoShader.Bind();
	
	//---------------------------------------Reflection Shader--------------------------------

	reflectionShader.Bind();
	linkReflectionShader();
	reflectionShader.Update(transform, myCamera);
	texture.Bind(0);
	mesh1.draw();
	mesh1.updateSphereData(*transform.GetPos(), 0.62f);

	//---------------------------------------------------------------------------------------

	//toonShader.Update(transform, myCamera);		//rimShader.Update(transform, myCamera);		//geoShader.Update(transform, myCamera);

	transform.SetPos(glm::vec3(2, -sinf(counter), 0.0));
	transform.SetRot(glm::vec3(0.0, counter*2, 0.0));
	transform.SetScale(glm::vec3(6, 6, 6));

	//---------------------------------------Geometry shader---------------------------------
	geoShader.Bind();
	linkGeoShader();
	geoShader.Update(transform, myCamera);
	texture1.Bind(0);
	mesh2.draw();
	mesh2.updateSphereData(*transform.GetPos(), 0.62f);
	//---------------------------------------------------------------------------------------

	transform.SetPos(glm::vec3(-10, -8, 30));
	transform.SetRot(glm::vec3(20, 135, -sinf(counter)));
	transform.SetScale(glm::vec3(0.3, 0.3, 0.3));

	myShader.Bind();
	linkMyShader();
	myShader.Update(transform, myCamera);
	mesh3.draw();
	mesh3.updateSphereData(*transform.GetPos(), 0.62f);





	counter = counter + 0.02f;

				
	glEnableClientState(GL_COLOR_ARRAY); 
	glEnd();

	_gameDisplay.swapBuffer();
} 