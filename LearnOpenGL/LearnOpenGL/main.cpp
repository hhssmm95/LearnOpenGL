#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();
	//glfw 옵션 설정(버전앞자리, 버전뒷자리, 프로필 설정)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//렌더링 윈도우 생성
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL_HelloWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//렌더링 윈도우의 컨텍스트를 현재 스레드의 주 컨텍스트로 지정하겠다고 GLFW에게 전달
	glfwMakeContextCurrent(window);

	//OS마다 다른 OpenGL함수 포인터의 주소를 로드 하기 위한 GLAD 초기화
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//뷰포트 크기 지정 (현재는 렌더링 윈도우 사이즈랑 같음)
	glViewport(0, 0, 800, 600);

	//콜백 등록
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	//렌더링 루프

	//glfwWindowShouldClose함수는 각 루프 시작 시마다 종료 명령이 지시되었는지 체크
	while (!glfwWindowShouldClose(window))
	{

		//입력 처리 함수
		processInput(window);


		//렌더링 명령

		//어떤 색으로 화면을 지울지 설정
		//상태를 설정하는 state-setting 함수
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//해당 함수를 통해 컬러 버퍼를 지울때마다 컬러 버퍼는 glClearColor함수에서 설정한 색으로 지워짐
		//실행에 현재 상태를 사용하는 state-using 함수
		glClear(GL_COLOR_BUFFER_BIT);



		//이벤트 확인 및 버퍼 교체

		//이벤트(키보드 입력이나 마우스 이동 이벤트 등)의 발생을 체크하고 윈도우 상태를 업데이트하며
		//정해진 콜백함수(등록 가능한)을 호출
		glfwPollEvents();

		//컬러 버퍼(GLFW 창 안의 각 픽셀들에 대한 값을 가지고 있는 버퍼)를 교체하며
		//컬러 버퍼는 반복중에 이미지를 그리고 화면에 출력하는 기능을 함
		glfwSwapBuffers(window);

	}
	





	//루프 종료 후 할당되었던 모든 자원들을 정리/삭제 하는 함수
	glfwTerminate();

	return 0;
}

//윈도우 창 크기가 조정될 때 마다 호출할 콜백 함 수
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window)
{
	//해당 버튼이 PRESS상태인지 RELEASE 상태인지를 확인하는 함수
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		//윈도우 종료 명령 (다음 루프 시작 시 체크하여 윈도우가 종료됨)
		glfwSetWindowShouldClose(window, true);
}