#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

int main()
{
	glfwInit();
	//glfw �ɼ� ����(�������ڸ�, �������ڸ�, ������ ����)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//������ ������ ����
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL_HelloWindow", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	//������ �������� ���ؽ�Ʈ�� ���� �������� �� ���ؽ�Ʈ�� �����ϰڴٰ� GLFW���� ����
	glfwMakeContextCurrent(window);

	//OS���� �ٸ� OpenGL�Լ� �������� �ּҸ� �ε� �ϱ� ���� GLAD �ʱ�ȭ
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//����Ʈ ũ�� ���� (����� ������ ������ ������� ����)
	glViewport(0, 0, 800, 600);

	//�ݹ� ���
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


	//������ ����

	//glfwWindowShouldClose�Լ��� �� ���� ���� �ø��� ���� ����� ���õǾ����� üũ
	while (!glfwWindowShouldClose(window))
	{

		//�Է� ó�� �Լ�
		processInput(window);


		//������ ���

		//� ������ ȭ���� ������ ����
		//���¸� �����ϴ� state-setting �Լ�
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		//�ش� �Լ��� ���� �÷� ���۸� ���ﶧ���� �÷� ���۴� glClearColor�Լ����� ������ ������ ������
		//���࿡ ���� ���¸� ����ϴ� state-using �Լ�
		glClear(GL_COLOR_BUFFER_BIT);



		//�̺�Ʈ Ȯ�� �� ���� ��ü

		//�̺�Ʈ(Ű���� �Է��̳� ���콺 �̵� �̺�Ʈ ��)�� �߻��� üũ�ϰ� ������ ���¸� ������Ʈ�ϸ�
		//������ �ݹ��Լ�(��� ������)�� ȣ��
		glfwPollEvents();

		//�÷� ����(GLFW â ���� �� �ȼ��鿡 ���� ���� ������ �ִ� ����)�� ��ü�ϸ�
		//�÷� ���۴� �ݺ��߿� �̹����� �׸��� ȭ�鿡 ����ϴ� ����� ��
		glfwSwapBuffers(window);

	}
	





	//���� ���� �� �Ҵ�Ǿ��� ��� �ڿ����� ����/���� �ϴ� �Լ�
	glfwTerminate();

	return 0;
}

//������ â ũ�Ⱑ ������ �� ���� ȣ���� �ݹ� �� ��
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


void processInput(GLFWwindow* window)
{
	//�ش� ��ư�� PRESS�������� RELEASE ���������� Ȯ���ϴ� �Լ�
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		//������ ���� ��� (���� ���� ���� �� üũ�Ͽ� �����찡 �����)
		glfwSetWindowShouldClose(window, true);
}