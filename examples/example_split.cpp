//
// Created by Troldal on 15/11/2019.
//

#include <string>
#include <vector>
#include <iostream>
#include <troldalgo.hpp>

int main() {

    std::string src(
            "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Maecenas vel interdum purus. Sed purus nisl, feugiat eu felis sit amet, feugiat tempor enim. Quisque bibendum gravida mauris, in ultrices nibh tincidunt a. Proin pretium odio a felis dignissim volutpat. Nulla iaculis maximus viverra. Nullam ac lacus pellentesque dolor sodales rhoncus id nec elit. Morbi posuere, diam a aliquam mattis, lorem sapien gravida est, eu feugiat massa justo non urna. Proin placerat euismod enim, eu porttitor turpis bibendum eu. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Nullam purus mauris, auctor sit amet urna vitae, ultricies porta erat. Fusce dapibus sem ullamcorper ligula pellentesque, quis imperdiet erat porttitor. Morbi a urna leo. Mauris vitae ultricies tortor. Pellentesque vel dui nisl. Nunc quis pretium felis.\n"
            "\n"
            "Nulla vel leo suscipit, volutpat risus sit amet, elementum ex. Donec venenatis maximus quam, ac auctor nulla mattis vitae. Aliquam erat volutpat. Curabitur rutrum feugiat placerat. Pellentesque convallis maximus sem. Fusce condimentum ligula a mauris scelerisque feugiat. Sed pretium, ligula non egestas lobortis, massa massa ultrices dolor, ac dictum est velit non odio. Ut ultricies et ante et porta. Sed tincidunt gravida arcu et commodo. Etiam pretium purus tempus dui consectetur rutrum vitae nec libero. Integer eget metus efficitur, semper nibh vitae, luctus ligula.\n"
            "\n"
            "Vestibulum ipsum lacus, lacinia sit amet sem id, sollicitudin posuere enim. Nullam eu erat ut dolor facilisis gravida sed vitae velit. In nec metus sem. Etiam congue urna eget turpis vulputate lobortis. Donec tincidunt malesuada facilisis. Quisque nec elit odio. Duis sagittis lectus ut vehicula hendrerit. Quisque ultricies viverra lorem nec suscipit. Suspendisse vel felis felis. Cras efficitur orci ante, eget rhoncus eros gravida eu.\n"
            "\n"
            "Fusce tempus bibendum sem at mollis. Maecenas ut tempor lectus, nec lacinia enim. Aenean luctus ligula dictum accumsan ullamcorper. Maecenas id purus ac nisi scelerisque sollicitudin. Aenean id eros vitae dolor luctus vulputate. Suspendisse sed sodales tortor. In interdum, est nec imperdiet suscipit, orci urna vulputate nunc, sed finibus metus leo quis nunc. In mollis tincidunt justo. Praesent eget efficitur erat, id vulputate turpis. Cras libero urna, rutrum quis posuere vel, ullamcorper sed nunc. Praesent in euismod nisl.\n"
            "\n"
            "Suspendisse turpis dolor, tempor nec dapibus sed, vestibulum at ante. Etiam volutpat egestas turpis, vel suscipit velit luctus et. Ut imperdiet vitae erat sed suscipit. Duis scelerisque, ante sit amet facilisis lacinia, nisl lacus sagittis diam, eget consectetur lacus lorem a lectus. Pellentesque ultrices nisl in velit varius sollicitudin. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Morbi rutrum luctus tincidunt. In hac habitasse platea dictumst. Pellentesque eu ante feugiat est mollis convallis. Aliquam in quam metus. Ut interdum dictum ipsum, et condimentum erat consequat eget. Fusce dignissim diam ac iaculis consectetur. Sed aliquam sapien sit amet lacus condimentum, et venenatis ex aliquam. Ut quis luctus sapien. Integer aliquet risus nunc, nec commodo nunc finibus id. Fusce ultricies dui a turpis lacinia, a molestie magna egestas.");

    std::string              sep(". ");
    std::vector<std::string> output;
    trl::split(src, std::back_inserter(output), trl::BySequence(sep));

    for (auto& word : output)
        std::cout << word << std::endl;

    std::cout << "Count: " << output.size() << std::endl;
}
