from setuptools import setup

package_name = 'mini_pupper_interfaces'  # <-- use your actual package folder name here

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Chuck Taylor',
    maintainer_email='your@email.com',
    description='mini_pupper_interfaces',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            # Format: 'command = module_path:function_name'
            'display_updater = mini_pupper_interfaces.display_updater:main',
        ],
    },
)
 