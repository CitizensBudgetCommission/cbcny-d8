module.exports = function (grunt) {
  grunt.config.merge({
    watch: {
      gesso: {
        files: ['<%= pkg.themePath %>/sass/**/*.scss'],
        tasks: ['styles'],
      },
      patternlab: {
        files: ['<%= pkg.themePath %>/pattern-lab/source/**/*'],
        tasks: ['shell:patternlab'],
        options: {
          livereload: true
        }
      },
      svgs: {
        files: ['<%= pkg.themePath %>/images/bg/*.svg'],
        tasks: [
          'images',
          'styles'
        ],
      },
    }
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-simple-watch');
}
