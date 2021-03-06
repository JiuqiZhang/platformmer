#pragma once
#define GL_SILENCE_DEPRECATION

#ifdef _WINDOWS
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES 1
#include <SDL.h>
#include "Map.h"
#include <SDL_opengl.h>
#include "glm/mat4x4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "ShaderProgram.h"

enum EntityType {PLAYER, PLATFORM, ENEMI};
enum AIType {JUMPER, SPINNER, PATROLER};
enum AIState {SPINING, JUMPING, PATROLING};


class Entity {
public:
	EntityType entityType;
	AIType aiType;
	AIState aiState;
	glm::vec3 position;
	glm::vec3 movement;
	glm::vec3 acceleration;
	glm::vec3 velocity;
	float speed;

	float width = 1;
	float height = 1;
	bool jump = false;
	float jumpPower = 0;
	GLuint textureID;

	int lives;
	bool menu = false;
	bool bottom = false;
	glm::mat4 modelMatrix;
	int *animFront = NULL;
	int *animLeft = NULL;
	int *animRight = NULL;
	int *animBack = NULL;

	int *animIndices = NULL;
	int animFrames = 0;
	int animIndex = 0;
	int animCols = 0;
	int animRows = 0;
	float animTime = 0;
	float ballRotate = 0;

	bool isActive = true;
	bool collidedTop = false;
	bool collidedBottom = false;
	bool collidedLeft = false;
	bool collidedRight = false;
	bool hit = false;
	bool defeat = false;
	bool win = false;
	bool lost = false;
	int enemy_num = 1;
	bool shake = false;

	bool restart = false;
	Entity();
	void CheckCollisionsX(Map* map);
	void CheckCollisionsY(Map* map);
 
	void Update(float deltaTime, Entity *player, Entity* objects, int objectCount, Map *map);
	void Render(ShaderProgram* program);
	void DrawSpriteFromTextureAtlas(ShaderProgram *program, GLuint textureID, int index);
	bool CheckCollision(Entity* other);
	void CheckCollisionsY(Entity* objects, int objectCount);
	void CheckCollisionsX(Entity* objects, int objectCount);
	void AI(Entity *player);
	void AIPatrol();
	void AIJump(Entity* player);
	void AISpin();
	void ifHit(Entity* enemies, int enemyCount);
};