
#include "SpaceGame.h"
#include "Engine.h"
#include "Assets.h"
#include "Player.h"
#include "Enemy.h"


using namespace nu;

bool SpaceGame::Initialize()
{
	Game::Initialize();

	m_scene = new Scene();
	m_scene->SetGame(this);

	/*
	m_titleFont = new Font();
	m_titleFont->Load("fonts/BreatheFireIii-PKLOB.ttf", 65);

	m_titleText = new Text(m_titleFont);
	m_titleText->Create(Engine::Get().GetRenderer(), "Hello World", Color{ 1, 1, 1 });

	m_gameFont = new Font();
	m_gameFont->Load("fonts/BreatheFireIii-PKLOB.ttf", 32);

	m_scoreText = new Text(m_gameFont);
	*/

	//Engine::Get().GetAudio().AddSound("laser", "audio/laser.mav");
	//Engine::Get().GetAudio().AddSound("explosion", "audio/explosion.mav");

	return true;
}



void SpaceGame::Update(float dt)
{
	switch (m_gameState)
	{
	case SpaceGame::GameState::Title:
		if (Engine::Get().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE))
		{
			m_gameState = GameState::StartGame;
		}
		break;
	case SpaceGame::GameState::StartGame:
		m_score = 0;
		m_lives = 3;
		m_gameState = GameState::StartLevel;
		break;
	case SpaceGame::GameState::StartLevel:
	{
		m_stateTimer -= dt;
		if (m_stateTimer <= 0)
		{
			m_gameState = GameState::Title;

			m_scene->RemoveAllActors();
			SpawnPlayer();
			m_spawnTime = 5.0f;
			m_gameState = GameState::Game;
		}
		break;
	}
	case SpaceGame::GameState::Game:
		m_spawnTimer = m_spawnTime;
		m_spawnTimer -= dt;
		if (m_spawnTimer <= 0.0f)
		{
			SpawnEnemy();
			m_spawnTimer = m_spawnTime;
		}

		break;
	case SpaceGame::GameState::GameOver:
		m_stateTimer -= dt;
		if (m_stateTimer <= 0)
		{
			m_gameState = GameState::Title;
			m_scene->RemoveAllActors();
		}
		break;
	default:
		break;

	}

	Game::Update(dt);
}
void SpaceGame::Draw(nu::Renderer& renderer)
{

	
	m_scene->Draw(renderer);

	switch (m_gameState)
	{
	case SpaceGame::GameState::Title:
		//draw title
		m_titleText->Draw(renderer, 400, 400);
		break;
	case SpaceGame::GameState::StartGame:
		
		break;
	case SpaceGame::GameState::StartLevel:
	
		break;
	break;
	case SpaceGame::GameState::Game:
		//draw score / lives
		m_scoreText->Create(renderer, "Score: " + std::to_string(m_score), { 1.0f, 1.0f, 1.0f });
		m_scoreText->Draw(renderer, 30, 30);

		m_livesText->Create(renderer, "Lives: " + std::to_string(m_lives), { 1.0f, 1.0f, 1.0f });
		m_livesText->Draw(renderer, renderer.GetWidth() - 60, 30);
		break;
	case SpaceGame::GameState::GameOver:
		break;
	default:
		break;

	}
}

void SpaceGame::OnPlayerDead()
{
	m_lives--;
	if (m_lives <= 0) m_gameState = GameState::GameOver;
	else m_gameState = GameState::StartLevel;

}

void SpaceGame::SpawnPlayer()
{
	
	PlayerDesc playerDesc;
	playerDesc.name = "Player";
	playerDesc.model = Assets::playerModel;
	playerDesc.transform = Transform{ Vector2{ 640.0f, 512.0f }, 0.0f, 15.0f };
	playerDesc.velocity = Vector2{ 0.0f, 0.0f };
	playerDesc.damping = 3.0f;
	playerDesc.speed = 2000.0f;

	Player* player = new Player{ playerDesc };
	m_scene->AddActor(player);
}

void SpaceGame::SpawnEnemy()
{
	
	EnemyDesc enemyDesc;
	enemyDesc.name = "Player";
	enemyDesc.model = Assets::playerModel;
	enemyDesc.transform = Transform{ Vector2{ 640.0f, 512.0f }, 0.0f, 15.0f };
	enemyDesc.velocity = Vector2{ 0.0f, 0.0f };
	enemyDesc.damping = 3.0f;
	enemyDesc.speed = 2000.0f;

	Enemy* enemy = new Enemy{ enemyDesc };
	m_scene->AddActor(enemy);
}
