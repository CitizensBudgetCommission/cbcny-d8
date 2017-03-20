module.exports = function (grunt) {
  grunt.registerTask('build', [
    'bower',
    'styles',
    'patternlab'
  ]);
};
