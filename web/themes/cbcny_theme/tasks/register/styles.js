module.exports = function (grunt) {
  grunt.registerTask('styles', [
    'sass_globbing:gesso',
    'sass:gesso',
    'postcss:gesso'
  ]);
};
